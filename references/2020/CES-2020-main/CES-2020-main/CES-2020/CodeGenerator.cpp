#include "stdafx.h"

namespace CodeGen
{
	void Head(Lex::LEX &lex, Log::LOG &log)
	{
		*(log.stream) << ".586\n";
		*(log.stream) << "\t.model flat, stdcall\n";
		*(log.stream) << "\tincludelib libucrt.lib\n";
		*(log.stream) << "\tincludelib kernel32.lib\n";
		*(log.stream) << "\tExitProcess PROTO : DWORD\n\n";
		*(log.stream) << "\tEXTRN outUs : proc\n";
		*(log.stream) << "\tEXTRN outStr : proc\n";
		*(log.stream) << "\tEXTRN outBool : proc\n";
		*(log.stream) << "\tEXTRN outSymb : proc\n";
		*(log.stream) << "\tEXTRN TIME : proc\n";
		*(log.stream) << "\tEXTRN DATE : proc \n";
		*(log.stream) << "\n.stack 4096\n";
	}
	void Const(Lex::LEX &lex, Log::LOG &log)
	{
		*(log.stream) << ".const\n";
		for (int i = 0; i < lex.idTable.size; i++)
		{
			if (lex.TI_EL(i).idtype == IT::L)
			{
				*(log.stream) << "\t" << lex.TI_EL(i).id;
				if (lex.TI_EL(i).iddatatype == IT::STRING)
				{
					*(log.stream) << " BYTE '" << lex.TI_EL(i).value.vString.str << "', 0\n";
				}
				else if (lex.TI_EL(i).iddatatype == IT::USINT)
				{
					*(log.stream) << " DWORD " << lex.TI_EL(i).value.vUsint << std::endl;
				}
				else if (lex.TI_EL(i).iddatatype == IT::BOOLEAN)
				{	
					*(log.stream) << " DWORD " << (int)lex.TI_EL(i).value.vBoolean << std::endl;
				}
				else
				{
					*(log.stream) << " DWORD " << "\'" << lex.TI_EL(i).value.vSymbol << "\'" << std::endl;
				}
			
			}
		}
	}
	void Data(Lex::LEX &lex, Log::LOG &log)
	{
		*(log.stream) << ".data\n";
		for (int i = 0; i < lex.lexTable.size; i++)
		{
			if (lex.LT_EL(i).lexema == LEX_NEW)
			{
				*(log.stream) << "\t" << lex.TI_EL(lex.LT_EL(i + 2).idxTI).id;
				*(log.stream) << " DWORD ?\n";

				i += 3;
			}
		}
	}
	void Code(Lex::LEX &lex, Log::LOG &log)
	{
		std::stack<std::string> parms;		
		std::string funcName = "";			
		bool isInfuncion = false, isMain = false,  isWhen = false, isOtherwise = false;
		int numOfPoint = 0, numOfWhen = 0, numOfOp = 0;				

		*(log.stream) << "\n.code\n\n";
		for (int i = 0; i < lex.lexTable.size; i++)
		{
			switch (lex.LT_EL(i).lexema)
			{
			case LEX_DEF:	
			{
				*(log.stream) << (funcName = lex.TI_EL(lex.LT_EL(++i).idxTI).id) << " PROC ";

				while (lex.LT_EL(i).lexema != LEX_RIGHTHESIS)
				{
					if (lex.LT_EL(i).idxTI != LT_TI_NULLIDX)
					{
						if (lex.TI_EL(lex.LT_EL(i).idxTI).idtype == IT::P)
						{
							*(log.stream) << lex.TI_EL(lex.LT_EL(i).idxTI).id << " : ";

							if (lex.TI_EL(lex.LT_EL(i).idxTI).iddatatype == IT::USINT)
							{
								*(log.stream) << "SDWORD";
							}
							else
							{
								*(log.stream) << "DWORD";
							}
						}
					
					}
					if (lex.LT_EL(i).lexema == LEX_COMMA)
						*(log.stream) << ", ";

					i++;
				}
				isInfuncion = true;
				*(log.stream) << std::endl;

				break;
			}
			case LEX_HEAD:
			{
				isMain = true;
				*(log.stream) << "main PROC\n";
				break;
			}
			case LEX_ASSIGN:
			{
				int resultPosition = i - 1;

				if (isOtherwise)
				{
					isWhen = false;
				}

				while (lex.LT_EL(i).lexema != LEX_DOT)
				{
					switch (lex.LT_EL(i).lexema)
					{
					case LEX_ID:
					case LEX_LITERAL:
					{

						if (lex.TI_EL(lex.LT_EL(i).idxTI).iddatatype == IT::STRING
							&& lex.TI_EL(lex.LT_EL(i).idxTI).idtype == IT::L)
						{
							*(log.stream) << "\tpush offset " << lex.TI_EL(lex.LT_EL(i).idxTI).id << std::endl;
							parms.push("offset " + lex.TI_EL(lex.LT_EL(i).idxTI).id);
						}
						else
						{
							*(log.stream) << "\tpush " << lex.TI_EL(lex.LT_EL(i).idxTI).id << std::endl;
							parms.push(lex.TI_EL(lex.LT_EL(i).idxTI).id);
						}

						break;
					}
					case LEX_SUBST:
					{

						for (int j = 1; j <= lex.LT_EL(i).priority; j++)
						{
							*(log.stream) << "\tpop edx\n";
						}

						if (!parms.empty())
						{
							for (int j = 1; j <= lex.LT_EL(i).priority; j++)
							{
								*(log.stream) << "\tpush " << parms.top() << std::endl;
								parms.pop();
							}
						}

						*(log.stream) << "\t\tcall " << lex.TI_EL(lex.LT_EL(i).idxTI).id << "\n\tpush eax\n";
						break;
					}
					case LEX_OPERATOR:
					case LEX_LOG_OPERATOR:
					{
						*(log.stream) << "\tpop ebx\n\tpop eax\n";

						switch (lex.LT_EL(i).operation)
						{
							case LEX_STAR:
							{
								*(log.stream) << "\tmul ebx\n";
								*(log.stream) << "\tcmp eax, " << TI_USINT_MAXVALUE + 1 << std::endl;
								*(log.stream) << "\tjl OK" << numOfOp << std::endl;
								*(log.stream) << "\tpush " << lex.LT_EL(i).pn << std::endl;
								*(log.stream) << "\tpush " << lex.LT_EL(i).sn << std::endl;
								*(log.stream) << "\tpush eax\n";
								*(log.stream) << "\tcall outUs\n";

								if(isMain)
									*(log.stream) << "\tjmp ERROR\n";
								else
								{
									*(log.stream) << "\tpush 0\n";
									*(log.stream) << "\tcall ExitProcess\n";
								}
								*(log.stream) << "OK" << numOfOp++ << ":\n";
								*(log.stream) << "\tpush eax\n";
								break;
							}
							case LEX_DIRSLASH:
							{
								*(log.stream) << "\tcdq\n";
								*(log.stream) << "\tcmp ebx, 0\n";
								*(log.stream) << "\tjne OK" << numOfOp << std::endl;
								*(log.stream) << "\tpush " << lex.LT_EL(i).pn << std::endl;
								*(log.stream) << "\tpush " << lex.LT_EL(i).sn << std::endl;
								*(log.stream) << "\tpush " << INT_FAST32_MIN << std::endl;
								*(log.stream) << "\tcall outUs\n";

								if (isMain)
									*(log.stream) << "\tjmp ERROR\n";
								else
								{
									*(log.stream) << "\tpush 0\n";
									*(log.stream) << "\tcall ExitProcess\n";
								}
								*(log.stream) << "OK" << numOfOp++ << ":\n";
								*(log.stream) << "\tdiv ebx\n";
								*(log.stream) << "\tpush eax\n";
								break;
							}
							case LEX_PLUS:
							{
								*(log.stream) << "\tadd eax, ebx\n";
								*(log.stream) << "\tcmp eax, " << TI_USINT_MAXVALUE + 1 << std::endl;
								*(log.stream) << "\tjl OK" << numOfOp << std::endl;
								*(log.stream) << "\tpush " << lex.LT_EL(i).pn << std::endl;
								*(log.stream) << "\tpush " << lex.LT_EL(i).sn << std::endl;
								*(log.stream) << "\tpush eax\n";
								*(log.stream) << "\tcall outUs\n";

								if (isMain)
									*(log.stream) << "\tjmp ERROR\n";
								else
								{
									*(log.stream) << "\tpush 0\n";
									*(log.stream) << "\tcall ExitProcess\n";
								}
								*(log.stream) << "OK" << numOfOp++ << ":\n";
								*(log.stream) << "\tpush eax\n";
								break;
							}
							case LEX_MINUS:
							{
								*(log.stream) << "\tsub eax, ebx\n";
								*(log.stream) << "\tcmp eax, " << TI_USINT_DEFAULT - 1<< std::endl;
								*(log.stream) << "\tjg OK" << numOfOp << std::endl;
								*(log.stream) << "\tpush " << lex.LT_EL(i).pn << std::endl;
								*(log.stream) << "\tpush " << lex.LT_EL(i).sn << std::endl;
								*(log.stream) << "\tpush eax\n";
								*(log.stream) << "\tcall outUs\n";

								if (isMain)
									*(log.stream) << "\tjmp ERROR\n";
								else
								{
									*(log.stream) << "\tpush 0\n";
									*(log.stream) << "\tcall ExitProcess\n";
								}
								*(log.stream) << "OK" << numOfOp++ << ":\n";
								*(log.stream) << "\tpush eax\n";
								break;
							}
							case LEX_LEFTSHIFT:
							{
								*(log.stream) << "\tcmp ebx, 8\n";
								*(log.stream) << "\tjg NOK" << numOfOp << std::endl;
								*(log.stream) << "\tmov cl, bl\n";
								*(log.stream) << "\tshl eax, cl\n";
								*(log.stream) << "\tcmp eax, " << TI_USINT_MAXVALUE + 1 << std::endl;
								*(log.stream) << "\tjl OK" << numOfOp << std::endl;
								*(log.stream) << "NOK" << numOfOp << ":\n";
								*(log.stream) << "\tpush " << lex.LT_EL(i).pn << std::endl;
								*(log.stream) << "\tpush " << lex.LT_EL(i).sn << std::endl;
								*(log.stream) << "\tpush eax\n";
								*(log.stream) << "\tcall outUs\n";
								if (isMain)
									*(log.stream) << "\tjmp ERROR\n";
								else
								{
									*(log.stream) << "\tpush 0\n";
									*(log.stream) << "\tcall ExitProcess\n";
								}
								*(log.stream) << "OK" << numOfOp++ << ":\n";
								*(log.stream) << "\tpush eax\n";
								break;
							}
							case LEX_RIGHTSHIFT:
							{
								*(log.stream) << "\tcmp ebx, 8\n";
								*(log.stream) << "\tjg NOK" << numOfOp << std::endl;
								*(log.stream) << "\tmov cl, bl\n";
								*(log.stream) << "\tshr eax, cl\n";
								*(log.stream) << "\tjmp OK" << numOfOp << std::endl;
								*(log.stream) << "NOK" << numOfOp << ":\n";
								*(log.stream) << "\txor eax, eax\n";
								*(log.stream) << "OK" << numOfOp++ << ":\n";
								*(log.stream) << "\tpush eax\n";				
								break;
							}
							case LEX_LESS:
							{
								*(log.stream) << "\tcmp eax, ebx"<< "\n";
								*(log.stream) << "\tjge M" << numOfPoint << "\n";
								*(log.stream) << "\tpush 1" << "\n";
								*(log.stream) << "\tjmp M" << numOfPoint + 1 << "\n";
								*(log.stream) << "M" << numOfPoint << ":\n";
								*(log.stream) << "\tpush 0" << "\n";
								*(log.stream) << "M" << numOfPoint + 1 << ":\n";
								break;
							}
							case LEX_GREATER:
							{
								*(log.stream) << "\tcmp eax, ebx"<< "\n";
								*(log.stream) << "\tjle M" << numOfPoint << "\n";
								*(log.stream) << "\tpush 1" << "\n";
								*(log.stream) << "\tjmp M" << numOfPoint + 1 << "\n";
								*(log.stream) << "M" << numOfPoint << ":\n";
								*(log.stream) << "\tpush 0" << "\n";
								*(log.stream) << "M" << numOfPoint + 1 << ":\n";
								break;
							}
							case LEX_EQU:
							{
								*(log.stream) << "\tcmp eax, ebx" << "\n";
								*(log.stream) << "\tjne M" << numOfPoint << "\n";
								*(log.stream) << "\tpush 1" << "\n";
								*(log.stream) << "\tjmp M" << numOfPoint + 1 << "\n";
								*(log.stream) << "M" << numOfPoint << ":\n";
								*(log.stream) << "\tpush 0" << "\n";
								*(log.stream) << "M" << numOfPoint + 1 << ":\n";

								break;
							}
							case LEX_NEQU:
							{
								*(log.stream) << "\tcmp eax, ebx" << "\n";
								*(log.stream) << "\tje M" << numOfPoint << "\n";
								*(log.stream) << "\tpush 1" << "\n";
								*(log.stream) << "\tjmp M" << numOfPoint + 1 << "\n";
								*(log.stream) << "M" << numOfPoint << ":\n";
								*(log.stream) << "\tpush 0" << "\n";
								*(log.stream) << "M" << numOfPoint + 1 << ":\n";
								break;
							}
						}
						break;
					}
					}
					i++;
				}
				numOfPoint++;
				*(log.stream) << "\tpop " << lex.TI_EL(lex.LT_EL(resultPosition).idxTI).id << "\n";

				if (isWhen)
				{
					isWhen = false;
					*(log.stream) << "\tjmp W" << numOfWhen + 1 << "\n";
					*(log.stream) << "W" << numOfWhen << ":\n";
				}
				break;
			}
			case LEX_RET:
			{
				*(log.stream) << "\tmov eax, ";

				i++;

				if (lex.TI_EL(lex.LT_EL(i).idxTI).idtype == IT::L)
				{
					if (lex.TI_EL(lex.LT_EL(i).idxTI).iddatatype == IT::USINT)
					{
						*(log.stream) << lex.TI_EL(lex.LT_EL(i++).idxTI).value.vUsint;
					}

					else if (lex.TI_EL(lex.LT_EL(i).idxTI).iddatatype == IT::BOOLEAN)
					{
						*(log.stream) << lex.TI_EL(lex.LT_EL(i++).idxTI).value.vBoolean;
					}	

					else if (lex.TI_EL(lex.LT_EL(i).idxTI).iddatatype == IT::SYMBOL)
					{
						*(log.stream) << lex.TI_EL(lex.LT_EL(i++).idxTI).value.vSymbol;
					}

					else
					{
						*(log.stream) << "offset " << lex.TI_EL(lex.LT_EL(i++).idxTI).id;
					}
						
				}
				else
				{
					*(log.stream) << lex.TI_EL(lex.LT_EL(i++).idxTI).id;
				}

				*(log.stream) << "\n\tret\n";
				break;
			}
			case LEX_CLOSE:
			{
				if (isMain && !isInfuncion)
				{
					*(log.stream) << "ERROR:\n";
					*(log.stream) << "\tpush 0\n";
					*(log.stream) << "\tcall ExitProcess\n";
					*(log.stream) << "main ENDP\n";
					*(log.stream) << "end main";
				}
				if (isInfuncion)
				{
					*(log.stream) << funcName << " ENDP\n\n";
					isInfuncion = false;
				}
				break;
			}
			case LEX_OUT:
			{
				if (isOtherwise)
				{
					isWhen = false;
				}

				if (lex.TI_EL(lex.LT_EL(i + 1).idxTI).iddatatype == IT::USINT)
				{
					*(log.stream) << "\tpush " << lex.TI_EL(lex.LT_EL(i + 1).idxTI).id << "\n\t\tcall outUs\n";
				}
				else if(lex.TI_EL(lex.LT_EL(i + 1).idxTI).iddatatype == IT::STRING)
				{
					if (lex.TI_EL(lex.LT_EL(i + 1).idxTI).idtype == IT::L)
					{
						*(log.stream) << "\tpush offset " << lex.TI_EL(lex.LT_EL(i + 1).idxTI).id << "\n\t\tcall outStr\n";
					}

					else
					{
						*(log.stream) << "\tpush  " << lex.TI_EL(lex.LT_EL(i + 1).idxTI).id << "\n\t\tcall outStr\n";
					}
					
				}
				else if (lex.TI_EL(lex.LT_EL(i + 1).idxTI).iddatatype == IT::BOOLEAN)
				{
					*(log.stream) << "\tpush " << lex.TI_EL(lex.LT_EL(i + 1).idxTI).id << "\n\t\tcall outBool\n";
				}
				else
				{
					*(log.stream) << "\tpush " << lex.TI_EL(lex.LT_EL(i + 1).idxTI).id << "\n\t\tcall outSymb\n";
				}

				if (isWhen)
				{
					isWhen = false;
					*(log.stream) << "\tjmp W" << numOfWhen + 1 << "\n";
					*(log.stream) << "\tW" << numOfWhen << ":\n";
				}
				break;
			}
			case LEX_WHEN:
			{
				isWhen = true;

				*(log.stream) << ";--------------------------условный блок------------------------------\n";

				if (lex.TI_EL(lex.LT_EL(i + 2).idxTI).iddatatype == IT::BOOLEAN)
				{
					*(log.stream) << "\tmov eax, " << lex.TI_EL(lex.LT_EL(i + 2).idxTI).id << "\n";
					*(log.stream) << "\tcmp eax, 1\n";
					*(log.stream) << "\tjne W" << numOfWhen << "\n";
				}
				else
				{
					*(log.stream) << "\tmov eax, " << lex.TI_EL(lex.LT_EL(i + 2).idxTI).id << "\n";
					*(log.stream) << "\tcmp eax, " << lex.TI_EL(lex.LT_EL(i + 4).idxTI).id << "\n";

					if (lex.LT_EL(i + 3).operation == LEX_GREATER)
					{
						*(log.stream) << "\tjle W" << numOfWhen << "\n";
					}
					else if (lex.LT_EL(i + 3).operation == LEX_LESS)
					{
						*(log.stream) << "\tjge W" << numOfWhen << "\n";
					}
					else if (lex.LT_EL(i + 3).operation == LEX_EQU)
					{
						*(log.stream) << "\tjne W" << numOfWhen << "\n";
					}
					else if (lex.LT_EL(i + 3).operation == LEX_NEQU)
					{
						*(log.stream) << "\tje W" << numOfWhen << "\n";
					}
				}
				break;
			}
			case LEX_OTHERWISE:
			{
				isOtherwise = true;
				isWhen = false;

				break;
			}
			case LEX_ENDW:
			{
				*(log.stream) << "W" << numOfWhen + 1 << ":\n";
				isOtherwise = false;

				*(log.stream) << ";----------------------------------------------------------------------\n";

				numOfWhen +=2;
				break;
			}

			}
		}

	}

	void ChangeNames(Lex::LEX &lex)
	{
		for (int i = 0; i < lex.idTable.size; i++)
		{
			if (lex.TI_EL(i).idtype != IT::L &&
				lex.TI_EL(i).id != DATE &&
				lex.TI_EL(i).id != TIME)
			{
				lex.TI_EL(i).id = lex.TI_EL(i).id + std::to_string(i);
			}
				
		}
	}

	void Generation(Lex::LEX &lex, Log::LOG log)
	{
		ChangeNames(lex);

		*(log.stream) << ";========================= шапка ==============================\n";
		Head(lex, log);

		*(log.stream) << ";=================== сегмент констант =========================\n";
		Const(lex, log);

		*(log.stream) << ";=================== сегмент данных ============================\n";
		Data(lex, log);

		*(log.stream) << ";=================== сегмент кода ==============================\n";
		Code(lex, log);

		*(log.stream) << "\n;=============================================================\n";
	}
}
#include "stdafx.h"	


namespace LA
{
	Graph graph[N_GRAPHS] = // ����� ��� �������� ���������
	{
		{ LEX_SEPARATORS, FST::FST(GRAPH_SEPARATORS)) },
		{ LEX_INIT, FST::FST(GRAPH_INIT) },
		{ LEX_LITERAL, FST::FST(GRAPH_NUMLIT) },
		{ LEX_LITERAL, FST::FST(GRAPH_CHARLIT) },
		{ LEX_FUNCTION, FST::FST(GRAPH_FUNCTION) },
		{ LEX_RETURN, FST::FST(GRAPH_RETURN) },
		{ LEX_OUT, FST::FST(GRAPH_OUT) },
		{ LEX_MAIN, FST::FST(GRAPH_MAIN) },
		{ LEX_LIB, FST::FST(GRAPH_EMatLib) },
		{ LEX_DIRSLASH, FST::FST(GRAPH_FORWARD_SLASH) },
		{ LEX_AVR, FST::FST(GRAPH_AVR) },
		{ LEX_POW, FST::FST(GRAPH_POW) },
		{ LEX_UNTIL, FST::FST(GRAPH_UNTIL)},
		{ LEX_NUM, FST::FST(GRAPH_INT) },
		{ LEX_CHAR, FST::FST(GRAPH_CHAR)},
		{ LEX_ID, FST::FST(GRAPH_ID) },		
		{ LEX_ERROR, FST::FST(GRAPH_ERROR)},
	};

	LEX StartLexAnalyze(In::IN& InStruct, Log::LOG& log, Parm::PARM& parm) //������ ������������ �������
	{
		LEX Tables;
		Tables.Lextable = LT::Create(LT_MAXSIZE);  // �������� ������� ������
		Tables.IDtable = IT::Create(TI_MAXSIZE);  // �������� ������� ���������������

		bool FlagEx = false; //��� �������
		bool flag1 = false;  //��� �������
		bool flag2 = false;  //��� �������
		bool isParam = false;     //���� �� ��������	
		int kol = 0;				//��� ����������
		int MainBody = 0;			//���� �� ������� �������
		int MyFunc = 0;				//���������� �� ���������� ��� ������������� ����������� �������
		int LibBody = 0;			//�������� ����������� ����������� ����������
		char Buffer[255] = "";			//����� ��� ����� ����������, ��������� � ��������
		char PrefixFunc[255] = ""; //����� ��� ����� �������

		IT::IDDATATYPE funcType;   // ��� �������
		IT::IDDATATYPE idType;   // ��� ��������������

		for (int i = 0; i < In::Words::amount; i++) // �������� �������� ������� ����
		{
			FlagEx = false;
			for (int j = 0; j < N_GRAPHS; j++)    // ���� ���������� ������� ��� �����	
			{

				FST::FST fstex(InStruct.words[i].word, graph[j].graph);   // ������� �������
				if (FST::execute(fstex)) // ���� ������ �������� �� 
				{
					FlagEx = true;
					switch (graph[j].lexema)     // ���� ���������� ���� ��� �������
					{
					case LEX_UNTIL:
					{
						LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line); // �������� �������� ��
						LT::Add(Tables.Lextable, entrylt); // ��������� �������� � ��
						break;
					}
					case LEX_MAIN:   // ���� ������� �-���
					{
						MainBody++;   //�������� � 0 �� 1 , �� ��������� , ���������� ����� 1 �� �-���
						if (MainBody > 1)    // ���� ������� ����� 1-�� ������� �-���
							Log::writeError(log.stream, Error::GetError(304, InStruct.words[i].line, NULL)); // ������ ������ � ������ ������

						strcpy_s(PrefixFunc, "m");
						LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line);   // ������ � �������, � ��������� ������ ������ 
						LT::Add(Tables.Lextable, entrylt);    // ���������� ������� � ������� 
						break; //�����
					}
					case LEX_LIB:   // ���� ����������� ����������
					{
						LibBody++;
						if (LibBody > 1)    // ���� ������� ����� 1-�� ����������
							Log::writeError(log.stream, Error::GetError(309, InStruct.words[i].line, NULL)); // ������ ������ � ������ ������

						LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line);// ������ � ������� , � ��������� ������ ������ 
						LT::Add(Tables.Lextable, entrylt);// ���������� ������� � ������� 
						break; //�����
					}

					case LEX_AVR:  // ������� ������� ������
					{
						MyFunc++;

						IT::Entry entryit("avr", i, IT::NUM, IT::SF); // ������ ������� �� � ���������� ���� ��������� ������
						IT::Add(Tables.IDtable, entryit);						 // ��������� ��������� �������
						LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line, IT::IsId(Tables.IDtable, InStruct.words[i].word)); // ��������
																																		 // �������� ������� ������
						LT::Add(Tables.Lextable, entrylt); //��������� � ������� ������
						Tables.IDtable.table[Tables.Lextable.table[i].idxTI].count_parm = 3;
						Tables.IDtable.table[Tables.Lextable.table[i].idxTI].parms[0] = 'n';
						Tables.IDtable.table[Tables.Lextable.table[i].idxTI].parms[1] = 'n';
						Tables.IDtable.table[Tables.Lextable.table[i].idxTI].parms[2] = 'n';
						break;
					}

					case LEX_POW: // ������� ������� ������� 
					{
						MyFunc++;
						IT::Entry entryit("pow", i, IT::NUM, IT::SF); // ������ ������� �� � ���������� ���� ��������� ������
						IT::Add(Tables.IDtable, entryit);						 // ��������� ��������� �������
						LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line, IT::IsId(Tables.IDtable, InStruct.words[i].word)); // ��������
																																		 // �������� ������� ������
						LT::Add(Tables.Lextable, entrylt); //��������� � ������� ������
						Tables.IDtable.table[Tables.Lextable.table[i].idxTI].count_parm = 2;
						Tables.IDtable.table[Tables.Lextable.table[i].idxTI].parms[0] = 'n';
						Tables.IDtable.table[Tables.Lextable.table[i].idxTI].parms[1] = 'n';
						break;
					}

					case LEX_ID://������������
					{
						if (Tables.Lextable.table[i - 1].lexema != LEX_FUNCTION && IT::IsId(Tables.IDtable, InStruct.words[i].word) == -1) //��������� ������� ��� ����� ��������������
						{
							strncpy(Buffer, PrefixFunc, ID_MAXSIZE - 1);
							strcat_s(Buffer, InStruct.words[i].word);
							strncpy(InStruct.words[i].word, Buffer, ID_MAXSIZE - 1);
						}

						if (IT::IsId(Tables.IDtable, InStruct.words[i].word) == -1) // ���� ������ ������������� �� ������ �������� 
						{
							if (Tables.Lextable.table[i - 1].lexema == LEX_FUNCTION) // ���� ���������� �������� ���� ������� ��������
							{
								strncpy_s(PrefixFunc, InStruct.words[i].word, ID_MAXSIZE - 1);

								funcType = idType;     // ��������� ��� ��������������
								IT::Entry entryit(PrefixFunc, i, idType, IT::F); // ������ ������� �� � ���������� ���� ��������� ������
								IT::Add(Tables.IDtable, entryit); // ��������� ��������� �������
								LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line, IT::IsId(Tables.IDtable, InStruct.words[i].word)); // �������� �������� ������� ������ (������� ����� ����� � ��)																 
								LT::Add(Tables.Lextable, entrylt); //��������� � ������� ������
								if (InStruct.words[i + 2].word[0] == LEX_RIGHTTHESIS) // ���� ������� ����� ���� - )  
									isParam = false; // ���� ������� ��� ����������
								else isParam = true; // ������� ����������
								break;

							}
							else if (Tables.Lextable.table[i - 1].lexema == LEX_NUM) //���� ���������� ������ ���� �������� ������ ���� ������ 
							{

								if (isParam == false) // ���� ������������� ���� ���������� �� �������� ����������
								{
									if (Tables.Lextable.table[i - 2].lexema != LEX_INIT) //���� �� ���� ���������������� ����������� ������ init
									{
										Log::writeError(log.stream, Error::GetError(302, InStruct.words[i].line, NULL));
										flag1 = true;
									}
									IT::Entry entryit(InStruct.words[i].word, i, idType, IT::V); // ������ ������� ��
									IT::Add(Tables.IDtable, entryit); //������� � ��
								}
								else if (isParam == true) // ����� ���� ��������
								{
									int curpos = Tables.IDtable.size;
									while (Tables.IDtable.table[curpos].idtype != IT::F)
										curpos--;
									if (kol > INT_MAXSIZE_PARM)
									{
										Log::writeError(log.stream, Error::GetError(314, InStruct.words[i].line, NULL));
										flag1 = true;
									}
									Tables.IDtable.table[curpos].parms[kol] = 'n';
									kol++;
									IT::Entry entryit(InStruct.words[i].word, i, idType, IT::P);// ������ ������� ��
									IT::Add(Tables.IDtable, entryit);//������� � ��
																	 //
									if (InStruct.words[i + 1].word[0] == LEX_RIGHTTHESIS) // ���� ��������� ������� - )
									{
										isParam = false; // ��������� �����������
										int curpos = Tables.IDtable.size;
										while (Tables.IDtable.table[curpos].idtype != IT::F)
											curpos--;
										Tables.IDtable.table[curpos].count_parm = kol;
										kol = 0;
									}
								}

								LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line, IT::IsId(Tables.IDtable, InStruct.words[i].word)); // �������� �������� ��
								LT::Add(Tables.Lextable, entrylt); // ���������� � ��
								break;
							}
							else if (Tables.Lextable.table[i - 1].lexema == LEX_CHAR) //���� ���������� ������ ���� �������� ��������� ���� ������
							{
								if (isParam == false) // ���� ������������� ���� ���������� �� �������� ����������
								{
									if (Tables.Lextable.table[i - 2].lexema != LEX_INIT) //���� �� ���� ���������������� ����������� ������ init
									{
										Log::writeError(log.stream, Error::GetError(302, InStruct.words[i].line, NULL));
										flag1 = true;
									}
									IT::Entry entryit(InStruct.words[i].word, i, idType, IT::V); // ������ ������� ��
									IT::Add(Tables.IDtable, entryit); //������� � ��
								}
								else if (isParam == true) // ����� ���� ��������
								{
									int curpos = Tables.IDtable.size;																							
									while (Tables.IDtable.table[curpos].idtype != IT::F)
										curpos--;
									Tables.IDtable.table[curpos].parms[kol] = 'w';
									kol++;
									if (kol == INT_MAXSIZE_PARM)
									{
										Log::writeError(log.stream, Error::GetError(300, InStruct.words[i].line, NULL));
										flag1 = true;
									}
									IT::Entry entryit(InStruct.words[i].word, i, idType, IT::P);// ������ ������� ��
									IT::Add(Tables.IDtable, entryit);//������� � ��
																	 //
									if (InStruct.words[i + 1].word[0] == LEX_RIGHTTHESIS) // ���� ��������� ������� - )
									{
										isParam = false; // ��������� �����������
										int curpos = Tables.IDtable.size;
										while (Tables.IDtable.table[curpos].idtype != IT::F)
											curpos--;
										Tables.IDtable.table[curpos].count_parm = kol;
										kol = 0;
									}
								}

								LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line, IT::IsId(Tables.IDtable, InStruct.words[i].word)); // �������� �������� ��
								LT::Add(Tables.Lextable, entrylt); // ���������� � ��
								break;
							}
							Log::writeError(log.stream, Error::GetError(82, InStruct.words[i].line, NULL)); // ���� ���� ���� �� ���� �� char, �� int
							flag1 = true;
						}
						// ����� �������� �� ���������������	
						else
						{
							if (Tables.Lextable.table[i - 1].lexema == LEX_NUM || Tables.Lextable.table[i - 1].lexema == LEX_CHAR || Tables.Lextable.table[i - 1].lexema == LEX_FUNCTION) // ���� ���������� ��� ��� ������ ��� ������� �������
							{
								Log::writeError(log.stream, Error::GetError(301, InStruct.words[i].line, NULL)); //����� ������ � ������� ���������������
								flag1 = true;
							}
							LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line, IT::IsId(Tables.IDtable, InStruct.words[i].word)); //�������� �������� ���� ������
							LT::Add(Tables.Lextable, entrylt); // ��������� �������� � ��
							break;
						}
						break;
					}
					case LEX_LITERAL: // ������� ��������
					{
						if (Tables.Lextable.table[i - 1].lexema == LEX_EQUAL) // �������� ���������� �������
						{

							IT::Entry entryit(LTRL, i, graph[j].graph.type, IT::L); // �������� �������� ���� �� � �������� �������
							IT::Add(Tables.IDtable, entryit); //���������� � ��
							IT::SetValue(Tables.IDtable, Tables.IDtable.size - 1, InStruct.words[i].word); // ������������ �������� ��������
							LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line, Tables.IDtable.size - 1); // �������� �������� ��
							LT::Add(Tables.Lextable, entrylt); // ���������� �������� � ��
							if (Tables.IDtable.table[IT::IsId(Tables.IDtable, InStruct.words[i - 2].word)].idtype == IT::F) // ���� ���������� ���� ���� �-���
							{
								Log::writeError(log.stream, Error::GetError(306, InStruct.words[i].line, NULL)); //������ ����������� �������� �-���
								flag1 = true;
							}
							if (Tables.IDtable.table[IT::IsId(Tables.IDtable, InStruct.words[i - 2].word)].idtype == IT::V ||    //���� ����� = ���� ���������� ��� ��������
								Tables.IDtable.table[IT::IsId(Tables.IDtable, InStruct.words[i - 2].word)].idtype == IT::P)
							{
								IT::SetValue(Tables.IDtable, IT::IsId(Tables.IDtable, InStruct.words[i - 2].word), InStruct.words[i].word); // ������������� �� �� �������� � ���� ���� ���������������
							}
							break;
						}

						else
						{
							IT::Entry entryit(LTRL, i, graph[j].graph.type, IT::L); // �������� �������� ���� �� � �������� �������
							IT::Add(Tables.IDtable, entryit); //���������� � �������
							IT::SetValue(Tables.IDtable, Tables.IDtable.size - 1, InStruct.words[i].word); // ������������ �������� ��������
							LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line, Tables.IDtable.size - 1); // �������� �������� ��
							LT::Add(Tables.Lextable, entrylt); // ���������� �������� � ��
						}
						break;
					}

					case LEX_SEPARATORS: // ������� �����������
					{

						switch (InStruct.words[i].word[0])
						{
						case LEX_SEPARATOR:
						{
							if (Tables.Lextable.table[i - 2].lexema == LEX_RETURN) // ����  ��������� �� 2 ���� ����� � ����� ������� return
							{
								if (Tables.IDtable.table[Tables.Lextable.table[i - 1].idxTI].iddatatype != funcType)
								{
									Log::writeError(log.stream, Error::GetError(311, InStruct.words[i].line, NULL));  // ������������ �������� �� ��������� � ����� �������
									flag1 = true;
								}
								//kol = 0;																		
								IT::IDDATATYPE retType; // �������� ���������� �������� �-���
								if (Tables.Lextable.table[i - 1].lexema == LEX_LITERAL) // ���� ���������� �������
									retType = Tables.IDtable.table[Tables.IDtable.size - 1].iddatatype; // ������ ������� � ���� ����� �-��� ��������
							}

							LT::Entry entrylt(InStruct.words[i].word[0], InStruct.words[i].line); // ������ ������� ��
							LT::Add(Tables.Lextable, entrylt); // ��������� �������� � ��
							break;

						}
						case LEX_PLUS:
						case LEX_EQUAL:
						case LEX_STAR:
						case LEX_MINUS:
						case LEX_DIRSLASH:
						case LEX_MORE:
						case LEX_LESS:
						case LEX_MREQ:
						case LEX_LSEQ:
						case LEX_NOT:
						case LEX_EQ:
						{

							if (Tables.Lextable.table[i - 1].lexema != LEX_ID && Tables.Lextable.table[i - 1].lexema != LEX_RIGHTTHESIS && Tables.Lextable.table[i - 1].lexema != LEX_LEFTTHESIS && Tables.Lextable.table[i - 1].lexema != LEX_LITERAL)
							{ //���� ������� �������� ��� �� ID, �� ��������, �� �������
								Log::writeError(log.stream, Error::GetError(103, InStruct.words[i].line, NULL)); //��� ����� �������� ������
								flag1 = true;
							}
							LT::Entry entrylt(InStruct.words[i].word[0], InStruct.words[i].line); // ������ ������� ��
							LT::Add(Tables.Lextable, entrylt); // ��������� �������� � ��
							break;
						}

						default:
						{
							LT::Entry entrylt(InStruct.words[i].word[0], InStruct.words[i].line); // ������ ������� ��
							LT::Add(Tables.Lextable, entrylt); // ��������� �������� � ������� ������
						}
						}
						break;
					}
					case LEX_NUM: // ������� ���� ������
					case LEX_CHAR:
						idType = graph[j].graph.type; // ���������� ���� ���� ������
					default:
					{
						LT::Entry entrylt(graph[j].lexema, InStruct.words[i].line); // �������� �������� ��
						LT::Add(Tables.Lextable, entrylt); // ��������� �������� � ��
						break;
					}
					}
					break;
				}

			}
			if (FlagEx == false) {
				throw ERROR_THROW_IN(102, InStruct.words[i].line, NULL); //������������� ������ ���������
			}
		}
		if (Tables.Lextable.size == LT_MAXSIZE)
		{
			throw ERROR_THROW(101);
		}
		if (Tables.IDtable.size == TI_MAXSIZE)
		{
			throw ERROR_THROW(100);
		}
		if (!MainBody) // ���� ������ �� �-���
		{
			flag1 = true;
			Log::writeError(log.stream, Error::GetError(303)); // ������ ���������� ������� �-���
		}
		
		if (flag1 == false && flag2 == false)
		{
			for (int i = 0; i < Tables.Lextable.size; i++) // �������� �������� � �� ����������� �������
			{
				if (Tables.Lextable.table[i].lexema == LEX_ID)
				{
					if (Tables.IDtable.table[Tables.Lextable.table[i].idxTI].idtype == IT::F) //���� ����� ������� ��� ������������� ������
					{
						if (Tables.Lextable.table[i + 1].lexema != LEX_LEFTTHESIS)
							Log::writeError(log.stream, Error::GetError(315, InStruct.words[i + 1].line, NULL));
					}
				}

				if (Tables.Lextable.table[i].lexema == LEX_STAR || Tables.Lextable.table[i].lexema == LEX_DIRSLASH || Tables.Lextable.table[i].lexema == LEX_MINUS || Tables.Lextable.table[i].lexema == LEX_PLUS)
				{//���� ������ ������ �������� ���-�� ������ ID,�������� � ������
					if (Tables.Lextable.table[i - 1].lexema != LEX_ID && Tables.Lextable.table[i - 1].lexema != LEX_LEFTTHESIS && Tables.Lextable.table[i - 1].lexema != LEX_RIGHTTHESIS && Tables.Lextable.table[i - 1].lexema != LEX_LITERAL)
						Log::writeError(log.stream, Error::GetError(205, InStruct.words[i + 1].line, NULL)); //������ � ���������� ���������
					if (Tables.Lextable.table[i + 1].lexema != LEX_ID && Tables.Lextable.table[i + 1].lexema != LEX_LEFTTHESIS && Tables.Lextable.table[i + 1].lexema != LEX_RIGHTTHESIS && Tables.Lextable.table[i + 1].lexema != LEX_LITERAL)
						Log::writeError(log.stream, Error::GetError(205, InStruct.words[i + 1].line, NULL)); //������ � ���������� ���������
				}
				if (Tables.Lextable.table[i].lexema == LEX_EQUAL) //�������� ����� � ��������� ����� ����� =
				{
					bool FlagForFun = false; //��� �������, ���������� � main
					int pos = i + 1;
					idType = Tables.IDtable.table[Tables.Lextable.table[i - 1].idxTI].iddatatype; //��� ���������� �� =
					if ((Tables.Lextable.table[pos].lexema == LEX_ID && Tables.IDtable.table[Tables.Lextable.table[pos].idxTI].idtype == IT::F) || ((Tables.Lextable.table[pos].lexema == LEX_POW || Tables.Lextable.table[pos].lexema == LEX_AVR) && Tables.IDtable.table[Tables.Lextable.table[pos].idxTI].idtype == IT::SF))
						FlagForFun = true; //����� �������� �������������� ����� �� ���������������� �� ����� ������� � main
					while (Tables.Lextable.table[pos].lexema != LEX_SEPARATOR)
					{
						if (idType == IT::STR && (Tables.Lextable.table[pos].lexema == LEX_STAR || Tables.Lextable.table[pos].lexema == LEX_DIRSLASH || Tables.Lextable.table[pos].lexema == LEX_MINUS || Tables.Lextable.table[pos].lexema == LEX_PLUS))
							Log::writeError(log.stream, Error::GetError(310, InStruct.words[i].line, NULL));//���� ���������� ���������� ���� � �� �������� ������ � ��� �����-�� ��������

						if (Tables.Lextable.table[pos].lexema == LEX_DIRSLASH && Tables.Lextable.table[pos + 1].lexema == LEX_LITERAL && Tables.IDtable.table[Tables.Lextable.table[pos + 1].idxTI].value.vNUM == 0)
							Log::writeError(log.stream, Error::GetError(307, InStruct.words[pos + 1].line, NULL)); //������� ��������� �� 0

						if ((Tables.Lextable.table[pos].lexema == LEX_ID || Tables.Lextable.table[pos].lexema == LEX_LITERAL) && Tables.IDtable.table[Tables.Lextable.table[pos].idxTI].iddatatype != idType && FlagForFun == false)
							Log::writeError(log.stream, Error::GetError(305, InStruct.words[pos].line, NULL)); //�������������� ����� � ��������� (���� ����� � ����� ������ �� ��������)
						pos++;
					}
					FlagForFun = false;
				}

			}
			bool FlagForMain = false; int some_count = 0; char some_buffer[INT_MAXSIZE_PARM];
			for (int i = 0; i < Tables.Lextable.size; i++)
			{
				if (Tables.Lextable.table[i].lexema == LEX_MAIN)
					FlagForMain = true;

				if (FlagForMain == true)
				{//�������� ����������
					if ((Tables.Lextable.table[i].lexema == LEX_ID && Tables.IDtable.table[Tables.Lextable.table[i].idxTI].idtype == IT::F) || ((Tables.Lextable.table[i].lexema == LEX_POW || Tables.Lextable.table[i].lexema == LEX_AVR) && Tables.IDtable.table[Tables.Lextable.table[i].idxTI].idtype == IT::SF))
					{
						int param = 0;

						if (Tables.Lextable.table[i + 1].lexema == LEX_LEFTTHESIS)
						{
							int k = i + 1;
							while (Tables.Lextable.table[k].lexema != LEX_RIGHTTHESIS)
							{
								if (Tables.Lextable.table[k].lexema == LEX_ID || Tables.Lextable.table[k].lexema == LEX_LITERAL)
								{
									if (Tables.IDtable.table[Tables.Lextable.table[k].idxTI].iddatatype == IT::STR || Tables.IDtable.table[Tables.Lextable.table[k].idxTI].iddatatype == IT::CH)
										some_buffer[some_count] = 'w';
									if (Tables.IDtable.table[Tables.Lextable.table[k].idxTI].iddatatype == IT::NUM)
										some_buffer[some_count] = 'n';
									some_count++;
								}
								k++;
							}
							if (some_count != Tables.IDtable.table[Tables.Lextable.table[i].idxTI].count_parm)
							{
								Log::writeError(log.stream, Error::GetError(312, InStruct.words[i + 1].line, NULL));
							}
							for (int r = 0; r < some_count; r++)
								if (some_buffer[r] != Tables.IDtable.table[Tables.Lextable.table[i].idxTI].parms[r] && some_count <= Tables.IDtable.table[Tables.Lextable.table[i].idxTI].count_parm)
								{
									Log::writeError(log.stream, Error::GetError(313, InStruct.words[i + 1].line, NULL));
								}
							some_count = 0;
						}
					}
				}
			}
		}
		return Tables; // ���������� �� ��
	}
}
#include "stdafx.h"

using namespace std;

namespace LA
{
	// ����������� ������
	LEX::LEX(int lexTableSize, int idTableSize)
	{
		this->lextable = LT::Create(lexTableSize);
		this->idtable = IT::Create(idTableSize);
	};
	LEX::LEX() { };

	GRAPH graph[] =
	{
		// ������ ������� ������������ ���� ������� �������

		// ���� ������

		{ LEX_INT, FST::FST(GRAPH_INT) },
		{ LEX_CHAR, FST::FST(GRAPH_CHAR) },
		{ LEX_STR, FST::FST(GRAPH_STR) },
		{ LEX_BOOL, FST::FST(GRAPH_BOOL) },

		// ��������������

		{ LEX_IDENTIFIER, FST::FST(GRAPH_IDENTIFIERS) },

		// ��������

		{ LEX_LITERAL, FST::FST(GRAPH_BOOL_TRUE) },
		{ LEX_LITERAL, FST::FST(GRAPH_BOOL_FALSE) },
		{ LEX_LITERAL, FST::FST(GRAPH_INT_LITERAL_8) },
		{ LEX_LITERAL, FST::FST(GRAPH_INT_LITERAL_10) },
		{ LEX_LITERAL, FST::FST(GRAPH_STRING_LITERAL) },
		{ LEX_LITERAL, FST::FST(GRAPH_CHAR_LITERAL) },

		// �������

		{ LEX_MAIN, FST::FST(GRAPH_MAIN) },
		{ LEX_RETURN, FST::FST(GRAPH_RETURN) },
		{ LEX_STRDUPLICATE, FST::FST(GRAPH_STRDUPLICATE) },
		{ LEX_STRLENGTH, FST::FST(GRAPH_STRLENGTH) },
		{ LEX_STRTRANSINT, FST::FST(GRAPH_STRTRANSINT) },
		{ LEX_STRTRANSINT, FST::FST(GRAPH_STRTRANSINT) },

		// ��������� ������ � �����

		{ LEX_WRITELINE, FST::FST(GRAPH_WRITELINE) },
		{ LEX_WRITE, FST::FST(GRAPH_WRITE) },
		{ LEX_CYCLE, FST::FST(GRAPH_CYCLE) },

		// ������

		{ LEX_LEFTBRACE_OPEN, FST::FST(GRAPH_LEFTBRACE_OPEN) },
		{ LEX_RIGHTBRACE_CLOSE, FST::FST(GRAPH_RIGHTBRACE_CLOSE) },
		{ LEX_LEFTHESIS_OPEN, FST::FST(GRAPH_LEFTHESIS_OPEN) },
		{ LEX_RIGHTHESIS_CLOSE, FST::FST(GRAPH_RIGHTHESIS_CLOSE) },

		// �������������� ���������

		{ LEX_ADDITION, FST::FST(GRAPH_ADDITION) },
		{ LEX_SUBSTRACTION, FST::FST(GRAPH_SUBSTRACTION) },
		{ LEX_MULTIPLICATION, FST::FST(GRAPH_MULTIPLICATION) },
		{ LEX_DIVISION, FST::FST(GRAPH_DIVISION) },
		{ LEX_REMAINDERDIVISION, FST::FST(GRAPH_REMAINDERDIVISION) },
		{ LEX_EQUALS, FST::FST(GRAPH_EQUALS) },
		{ LEX_MORE, FST::FST(GRAPH_MORE) },
		{ LEX_LESS, FST::FST(GRAPH_LESS) },
		{ LEX_MOREEQUAL, FST::FST(GRAPH_MOREEQUAL) },
		{ LEX_LESSEQUAL, FST::FST(GRAPH_LESSEQUAL) },
		{ LEX_INEQUALITY, FST::FST(GRAPH_INEQUALITY) },
		{ LEX_NOTEQUALS, FST::FST(GRAPH_NOTEQUALS) },

		// ������

		{ LEX_COMMA, FST::FST(GRAPH_COMMA) },
		{ LEX_SEMICOLON, FST::FST(GRAPH_SEMICOLON) },
	};

	// ���������� ��� �������
	//char LexType(Tokens::Token token)
	//{
	//	for (int i = 0; i < LENGTHOF(graph); i++)
	//	{
	//		FST::FST fstlex = FST::FST(token.token, graph[i].graph);
	//		if (FST::execute(fstlex))
	//		{
	//			return graph[i].lex;
	//		}
	//	}
	//	throw ERROR_THROW_IN(117, token.line, 0);
	//}

	char LexType(Tokens::Token token)
	{
		std::cout << "LexType: Token = " << token.token << " on line " << token.line << std::endl;

		for (int i = 0; i < LENGTHOF(graph); i++)
		{
			std::cout << "Creating FST for token: " << token.token << " using graph " << i << std::endl;
			FST::FST fstlex = FST::FST(token.token, graph[i].graph);

			if (FST::execute(fstlex))
			{
				std::cout << "Token " << token.token << " recognized as " << (int)graph[i].lex << std::endl;
				return graph[i].lex;
			}
		}
		std::cout << "Token " << token.token << " is not recognized, throwing error 117" << std::endl;
		throw ERROR_THROW_IN(117, token.line, 0);
	}
	LEX FillingInTables(Tokens::TokenTable tokenTable)
	{
		LEX lex = LEX(LT_MAXSIZE, TI_MAXSIZE);
		char lexema;
		std::string id;
		int lineIT = TI_NULLIDX;
		std::stack<int> areaOfVisibility;
		areaOfVisibility.push(0);
		int globalAreaOfVisibility = 0;
		IT::IDTYPE idType = IT::IDTYPE::P;
		IT::IDDATATYPE idDataType = IT::IDDATATYPE::UNDF;
		int isNotGlobal = 0;
		bool isMain = false;
		int numOfLit = 0;
		bool isDeclare = false;
		bool GlobalFunIsFound = false;

		std::cout << "Starting FillingInTables" << std::endl;

		for (int index = 0; index < tokenTable.size; index++)
		{
			std::cout << "Processing token: " << tokenTable.table[index].token
				<< " at line: " << tokenTable.table[index].line
				<< ", line position: " << tokenTable.table[index].linePosition << std::endl;

			lexema = LexType(tokenTable.table[index]);
			std::cout << "Lexeme identified: " << (int)lexema << " (" << tokenTable.table[index].token << ")" << std::endl;

			switch (lexema)
			{
			case LEX_IDENTIFIER:
				lineIT = SearchID(areaOfVisibility, std::string(tokenTable.table[index].token), lex.idtable);
				if (lineIT == TI_NULLIDX)
				{
					lineIT = SearchGlobalFunctionID(globalAreaOfVisibility, std::string(tokenTable.table[index].token), lex.idtable);
					if (lineIT != TI_NULLIDX)
					{
						GlobalFunIsFound = true;
						std::cout << "Global function ID found for token: " << tokenTable.table[index].token << std::endl;
					}
				}

				if (lineIT == TI_NULLIDX && isDeclare || lineIT == TI_NULLIDX && !isNotGlobal)
				{
					id = std::string(tokenTable.table[index].token) + std::to_string(areaOfVisibility.top());
					std::cout << "New identifier declaration: " << id << std::endl;
					IT::Add(lex.idtable, IT::CreateEntry(lex.lextable.size, id, idDataType, idType));
				}
				else if (lineIT == TI_NULLIDX)
				{
					std::cout << "Error: Identifier not found and not declared, throwing error 135" << std::endl;
					throw ERROR_THROW_IN(135, tokenTable.table[index].line, tokenTable.table[index].linePosition);
				}
				else if (lineIT != TI_NULLIDX && isDeclare)
				{
					std::cout << "Error: Duplicate identifier declaration, throwing error 136" << std::endl;
					throw ERROR_THROW_IN(136, tokenTable.table[index].line, tokenTable.table[index].linePosition);
				}

				LT::Add(lex.lextable, LT::CreateEntry(lexema, tokenTable.table[index].line, lineIT));
				idType = IT::IDTYPE::P;
				idDataType = IT::IDDATATYPE::UNDF;
				GlobalFunIsFound = false;
				isDeclare = false;
				break;

			case LEX_LITERAL:
				if (tokenTable.table[index].token[0] == '"')
				{
					if (tokenTable.table[index].length == 2)
					{
						std::cout << "Error: Empty string literal detected, throwing error 149" << std::endl;
						throw ERROR_THROW_IN(149, tokenTable.table[index].line, tokenTable.table[index].linePosition);
					}
					id = "str" + std::to_string(numOfLit++);
					IT::Add(lex.idtable, IT::CreateEntry(lex.lextable.size, id, IT::IDDATATYPE::STR, IT::IDTYPE::L, std::string(tokenTable.table[index].token)));
					std::cout << "String literal added with ID: " << id << std::endl;
				}
				LT::Add(lex.lextable, LT::CreateEntry(lexema, tokenTable.table[index].line, lex.idtable.size - 1));
				break;

			default:
				LT::Add(lex.lextable, LT::CreateEntry(lexema, tokenTable.table[index].line));

				if (lexema == LEX_LEFTBRACE_OPEN)
				{
					areaOfVisibility.push(lex.lextable.size - 1);
					isNotGlobal++;
					std::cout << "Entering new scope, isNotGlobal: " << isNotGlobal << std::endl;
				}
				else if (lexema == LEX_RIGHTBRACE_CLOSE)
				{
					areaOfVisibility.pop();
					isNotGlobal--;
					std::cout << "Exiting scope, isNotGlobal: " << isNotGlobal << std::endl;
				}
				else if (lexema == LEX_MAIN)
				{
					if (isMain)
					{
						std::cout << "Error: Duplicate 'main' function, throwing error 131" << std::endl;
						throw ERROR_THROW_IN(131, tokenTable.table[index].line, tokenTable.table[index].linePosition);
					}
					isMain = true;
					std::cout << "'main' function found at line " << tokenTable.table[index].line << std::endl;
				}
				break;
			}
		}

		if (!isMain)
		{
			std::cout << "Error: 'main' function not found, throwing error 134" << std::endl;
			throw ERROR_THROW(134);
		}

		std::cout << "FillingInTables completed successfully" << std::endl;
		return lex;
	}

	//LEX FillingInTables(Tokens::TokenTable tokenTable)
	//{
	//	LEX lex = LEX(LT_MAXSIZE, TI_MAXSIZE);
	//	char lexema;
	//	string id;
	//	int lineIT = TI_NULLIDX;
	//	stack<int> areaOfVisibility;
	//	areaOfVisibility.push(0);
	//	int globalAreaOfVisibility = 0;
	//	char* currentVisibility = new char[0];
	//	IT::IDTYPE idType = IT::IDTYPE::P;
	//	IT::IDDATATYPE idDataType = IT::IDDATATYPE::UNDF;
	//	int isNotGlobal = 0;
	//	bool isMain = false;
	//	int numOfLit = 0;
	//	bool isDeclare = false;
	//	bool GlobalFunIsFound = false;

	//	for (int index = 0; index < tokenTable.size; index++)
	//	{
	//		switch (lexema = LexType(tokenTable.table[index]))
	//		{
	//		case LEX_IDENTIFIER:
	//			lineIT = SearchID(areaOfVisibility, string(tokenTable.table[index].token), lex.idtable);
	//			// ���� id ���������� �� ������ � IT �� ���� id �������
	//			if (lineIT == TI_NULLIDX)
	//			{
	//				lineIT = SearchGlobalFunctionID(globalAreaOfVisibility, string(tokenTable.table[index].token), lex.idtable);
	//				if (lineIT != TI_NULLIDX)
	//					GlobalFunIsFound = true;
	//			}
	//			// ���� id �� ������ � IT �� ��� ����������
	//			if (lineIT == TI_NULLIDX && isDeclare || lineIT == TI_NULLIDX && !isNotGlobal)
	//			{
	//				lineIT = lex.idtable.size;
	//				id = string(tokenTable.table[index].token) + to_string(areaOfVisibility.top());
	//				IT::Add(lex.idtable, IT::CreateEntry(lex.lextable.size, id, idDataType, idType));
	//			}
	//			else if (lineIT == TI_NULLIDX)
	//			{
	//				throw ERROR_THROW_IN(135, tokenTable.table[index].line, tokenTable.table[index].linePosition);
	//			}
	//			// ���� id ���� � IT
	//			else if (lineIT != TI_NULLIDX && isDeclare)
	//			{
	//				if ((IT::GetEntry(lex.idtable, lineIT)).id == string(tokenTable.table[index].token) + to_string(areaOfVisibility.top()) || GlobalFunIsFound
	//					|| (IT::GetEntry(lex.idtable, lineIT)).id == string(tokenTable.table[index].token) + to_string(globalAreaOfVisibility) && ((IT::GetEntry(lex.idtable, lineIT)).idType == IT::IDTYPE::F)
	//					|| (IT::GetEntry(lex.idtable, lineIT)).id == string(tokenTable.table[index].token) + to_string(globalAreaOfVisibility) && ((IT::GetEntry(lex.idtable, lineIT)).idType == IT::IDTYPE::P) && (isNotGlobal == 1))
	//				{
	//					throw ERROR_THROW_IN(136, tokenTable.table[index].line, tokenTable.table[index].linePosition);
	//				}
	//				else
	//				{
	//					lineIT = lex.idtable.size;
	//					id = string(tokenTable.table[index].token) + to_string(areaOfVisibility.top());
	//					IT::Add(lex.idtable, IT::CreateEntry(lex.lextable.size, id, idDataType, idType));
	//				}
	//			}
	//			// ����� ������� ��� ���������
	//			else if (lineIT != TI_NULLIDX && idType == IT::IDTYPE::F)
	//				throw ERROR_THROW_IN(143, tokenTable.table[index].line, tokenTable.table[index].linePosition);


	//			LT::Add(lex.lextable, LT::CreateEntry(lexema, tokenTable.table[index].line, lineIT));
	//			idType = IT::IDTYPE::P;
	//			idDataType = IT::IDDATATYPE::UNDF;
	//			GlobalFunIsFound = false;
	//			isDeclare = false;
	//			break;
	//		case LEX_LITERAL:
	//			// ��������� �������
	//			if (tokenTable.table[index].token[0] == '"')
	//			{
	//				if (tokenTable.table[index].length == 2)
	//				{
	//					throw ERROR_THROW_IN(149, tokenTable.table[index].line, tokenTable.table[index].linePosition);
	//				}
	//				id = "str" + to_string(numOfLit++);
	//				IT::Add(lex.idtable, IT::CreateEntry(lex.lextable.size, id, IT::IDDATATYPE::STR, IT::IDTYPE::L, string(tokenTable.table[index].token)));
	//			}
	//			// ������� char
	//			if (tokenTable.table[index].token[0] == '\'' && tokenTable.table[index].token[2] == '\'') {
	//				char c = tokenTable.table[index].token[1];
	//				id = "char" + to_string(numOfLit++);
	//				IT::Add(lex.idtable, IT::CreateEntry(lex.lextable.size, id, IT::IDDATATYPE::CHAR, IT::IDTYPE::L, c));
	//			}
	//			// ������� bool
	//			else if (tokenTable.table[index].token[0] == 't' || tokenTable.table[index].token[0] == 'f')
	//			{
	//				bool vBool;
	//				if (tokenTable.table[index].token[0] == 't')
	//					vBool = true;
	//				else vBool = false;

	//				id = "bool" + to_string(numOfLit++);
	//				IT::Add(lex.idtable, IT::CreateEntry(lex.lextable.size, id, IT::IDDATATYPE::BOOL, IT::IDTYPE::L, vBool));
	//			}
	//			// ������������� �������
	//			else
	//			{
	//				int vShort;
	//				switch (tokenTable.table[index].token[strlen(tokenTable.table[index].token) - 1])
	//				{
	//				case 'B':
	//					vShort = strtol(tokenTable.table[index].token, NULL, 2);
	//					break;
	//				case 'O':
	//					vShort = strtol(tokenTable.table[index].token, NULL, 8);
	//					break;
	//				case 'H':
	//					vShort = strtol(tokenTable.table[index].token, NULL, 16);
	//					break;
	//				default:
	//					vShort = strtol(tokenTable.table[index].token, NULL, 10);
	//					break;
	//				}
	//				if (vShort < -32768 || vShort > 32767)
	//					throw ERROR_THROW_IN(133, tokenTable.table[index].line, tokenTable.table[index].linePosition);
	//				id = "short" + to_string(numOfLit++);
	//				IT::Add(lex.idtable, IT::CreateEntry(lex.lextable.size, id, IT::IDDATATYPE::SHORT, IT::IDTYPE::L, vShort));
	//			}
	//			LT::Add(lex.lextable, LT::CreateEntry(lexema, tokenTable.table[index].line, lex.idtable.size - 1));
	//			break;
	//		default:
	//			LT::Add(lex.lextable, LT::CreateEntry(lexema, tokenTable.table[index].line));

	//			switch (lexema)
	//			{
	//			case LEX_LEFTBRACE_OPEN:
	//				areaOfVisibility.push(lex.lextable.size - 1);
	//				isNotGlobal++;
	//				break;
	//			case LEX_RIGHTBRACE_CLOSE:
	//				areaOfVisibility.pop();
	//				isNotGlobal--;
	//				break;
	//			case LEX_INT:
	//				idDataType = IT::IDDATATYPE::SHORT;
	//				break;
	//			case LEX_STR:
	//				idDataType = IT::IDDATATYPE::STR;
	//				break;
	//			case LEX_BOOL:
	//				idDataType = IT::IDDATATYPE::BOOL;
	//				break;
	//			case LEX_CHAR:
	//				idDataType = IT::IDDATATYPE::CHAR;
	//				break;
	//			case LEX_MAIN:
	//				if (isMain)
	//					throw ERROR_THROW_IN(131, tokenTable.table[index].line, tokenTable.table[index].linePosition);
	//				isMain = true;
	//				if (!isNotGlobal)
	//				{
	//					globalAreaOfVisibility++;
	//					if (areaOfVisibility.top() != 0)
	//						areaOfVisibility.pop();
	//					areaOfVisibility.push(globalAreaOfVisibility);
	//				}
	//				break;
	//			default:
	//				break;
	//			}

	//			break;
	//		}
	//	}

	//	if (!isMain)
	//		throw ERROR_THROW(134);
	//	return lex;
	//}

	// ����� id � IT
	int SearchID(stack<int> areaOfVisibility, string id, IT::IdTable& idtable)
	{
		char* currentVisibility = new char[0];
		string searchingID;
		int result = TI_NULLIDX;
		while (areaOfVisibility.top() != 0)
		{
			itoa(areaOfVisibility.top(), currentVisibility, 10);
			areaOfVisibility.pop();
			searchingID = id + string(currentVisibility);
			result = IT::IsId(idtable, searchingID);
			if (result != TI_NULLIDX)
				return result;

		}
		return result;
	}

	// ����� id ������� � IT
	int SearchGlobalFunctionID(int globalAreaOfVisibility, string id, IT::IdTable& idtable)
	{
		int result = TI_NULLIDX;
		string searchingID;
		for (int i = 1; i < globalAreaOfVisibility; i++)
		{
			searchingID = id + to_string(i);
			result = IT::IsId(idtable, searchingID);
			if (result != TI_NULLIDX && idtable.table[result].idType == IT::IDTYPE::F)
				return result;
		}
		return TI_NULLIDX;
	}
}
#include "stdafx.h"
#include "SemanticAnalyzer.h"

void CallSemantic(LT::LexTable& lextable, IT::IdTable& idtable)
{
	Functions functions = Create(MAX_FUNCTIONS_COUNT);
	CheckTypeMatching(lextable, idtable);
	FillFunctions(functions, idtable);
	CheckFuncParam(functions, idtable, lextable);
	CheckFuncParamCount(lextable, idtable);
	CheckReturnType(lextable, idtable);
}
// Проверка выражений и соответсвия типов
void CheckTypeMatching(LT::LexTable& lextable, IT::IdTable& idtable)
{
	for (int i = 0; i < lextable.size; i++)
	{
		if (lextable.table[i].lexema == LEX_EQUALS)
		{
			if (idtable.table[lextable.table[i - 1].idxTI].idType != IT::IDTYPE::V && idtable.table[lextable.table[i - 1].idxTI].idType != IT::IDTYPE::P)
				throw ERROR_THROW_IN(142, lextable.table[i - 1].sn, 0);
			IT::IDDATATYPE type = idtable.table[lextable.table[i - 1].idxTI].idDataType;

			int indexB = 0;
			bool isFirst = true;
			IT::IDDATATYPE type1 = IT::IDDATATYPE::UNDF;

			switch (type)
			{
			case IT::IDDATATYPE::BOOL:
			{
				bool foundComparisonOperator = false;
				bool foundArithmeticOperator = false;

				while (lextable.table[i + indexB].lexema != LEX_SEMICOLON)
				{
					char lex = lextable.table[i + indexB].lexema;

					if (lex == LEX_IDENTIFIER || lex == LEX_LITERAL)
					{
						IT::IDDATATYPE currentType = idtable.table[lextable.table[i + indexB].idxTI].idDataType;
						if (isFirst)
						{
							type1 = currentType;
							isFirst = false;
						}

						if (idtable.table[lextable.table[i + indexB].idxTI].idType == IT::IDTYPE::F)
						{
							if (idtable.table[lextable.table[i + indexB].idxTI].idDataType != IT::IDDATATYPE::BOOL)
								throw ERROR_THROW_IN(137, lextable.table[i + indexB].sn, 0);

							int countOfHesis = 0;
							if (lextable.table[i + indexB + 1].lexema != LEX_LEFTHESIS_OPEN)
								throw ERROR_THROW_IN(144, lextable.table[i + indexB].sn, 0);

							do
							{
								indexB++;
								if (lextable.table[i + indexB].lexema == LEX_LEFTHESIS_OPEN)
									countOfHesis++;
								if (lextable.table[i + indexB].lexema == LEX_RIGHTHESIS_CLOSE)
									countOfHesis--;
							} while (countOfHesis != 0);
						}
					}
					else if (lex == LEX_ADDITION || lex == LEX_SUBSTRACTION ||
						lex == LEX_DIVISION || lex == LEX_MULTIPLICATION || lex == LEX_REMAINDERDIVISION)
					{
						foundArithmeticOperator = true;
					}

					else if (lex == LEX_MORE || lex == LEX_LESS || lex == LEX_MOREEQUAL ||
						lex == LEX_LESSEQUAL || lex == LEX_INEQUALITY || lex == LEX_NOTEQUALS)
					{
						foundComparisonOperator = true;
					}

					indexB++;
				}
				if (foundArithmeticOperator && !foundComparisonOperator)
					throw ERROR_THROW_IN(602, lextable.table[i].sn, 0);
			}
			break;
			case IT::IDDATATYPE::STR:
				for (int j = 0; lextable.table[i + j].lexema != LEX_SEMICOLON; j++)
				{
					if (lextable.table[i + j].lexema == LEX_ADDITION || lextable.table[i + j].lexema == LEX_SUBSTRACTION
						|| lextable.table[i + j].lexema == LEX_DIVISION || lextable.table[i + j].lexema == LEX_MULTIPLICATION
						|| lextable.table[i + j].lexema == LEX_REMAINDERDIVISION || lextable.table[i + j].lexema == LEX_LESS
						|| lextable.table[i + j].lexema == LEX_MORE || lextable.table[i + j].lexema == LEX_INEQUALITY
						|| lextable.table[i + j].lexema == LEX_NOTEQUALS || lextable.table[i + j].lexema == LEX_LESSEQUAL
						|| lextable.table[i + j].lexema == LEX_MOREEQUAL)
						throw ERROR_THROW_IN(146, lextable.table[i + j].sn, 0);
					if (lextable.table[i + j].lexema == LEX_IDENTIFIER || lextable.table[i + j].lexema == LEX_LITERAL)
					{
						if (idtable.table[lextable.table[i + j].idxTI].idType == IT::IDTYPE::F)
						{
							if (idtable.table[lextable.table[i + j].idxTI].idDataType != type)
								throw ERROR_THROW_IN(137, lextable.table[i + j].sn, 0);
							int countOfHesis = 0;
							if (lextable.table[i + j + 1].lexema != LEX_LEFTHESIS_OPEN)
								throw ERROR_THROW_IN(144, lextable.table[i + j].sn, 0);
							do
							{
								j++;
								if (lextable.table[i + j].lexema == LEX_LEFTHESIS_OPEN)
									countOfHesis++;
								if (lextable.table[i + j].lexema == LEX_RIGHTHESIS_CLOSE)
									countOfHesis--;
							} while (countOfHesis != 0);
						}
						else if (idtable.table[lextable.table[i + j].idxTI].idDataType != type)
							throw ERROR_THROW_IN(137, lextable.table[i + j].sn, 0);
					}
				}

				break;
			case IT::IDDATATYPE::CHAR:
			{
				int index = 0;
				while (lextable.table[i + index].lexema != LEX_SEMICOLON)
				{
					if (lextable.table[i + index].lexema == LEX_ADDITION || lextable.table[i + index].lexema == LEX_SUBSTRACTION
						|| lextable.table[i + index].lexema == LEX_DIVISION || lextable.table[i + index].lexema == LEX_MULTIPLICATION
						|| lextable.table[i + index].lexema == LEX_REMAINDERDIVISION || lextable.table[i + index].lexema == LEX_LESS
						|| lextable.table[i + index].lexema == LEX_MORE || lextable.table[i + index].lexema == LEX_INEQUALITY
						|| lextable.table[i + index].lexema == LEX_NOTEQUALS || lextable.table[i + index].lexema == LEX_LESSEQUAL
						|| lextable.table[i + index].lexema == LEX_MOREEQUAL)
						throw ERROR_THROW_IN(151, lextable.table[i + index].sn, 0);

					if (lextable.table[i + index].lexema == LEX_IDENTIFIER || lextable.table[i + index].lexema == LEX_LITERAL)
					{
						if (idtable.table[lextable.table[i + index].idxTI].idType == IT::IDTYPE::F)
						{
							if (idtable.table[lextable.table[i + index].idxTI].idDataType != IT::IDDATATYPE::CHAR)
								throw ERROR_THROW_IN(137, lextable.table[i + index].sn, 0);
							int countOfHesis = 0;
							if (lextable.table[i + index + 1].lexema != LEX_LEFTHESIS_OPEN)
								throw ERROR_THROW_IN(144, lextable.table[i + index].sn, 0);
							do
							{
								index++;
								if (lextable.table[i + index].lexema == LEX_LEFTHESIS_OPEN)
									countOfHesis++;
								if (lextable.table[i + index].lexema == LEX_RIGHTHESIS_CLOSE)
									countOfHesis--;
							} while (countOfHesis != 0);
						}
						else
						{
							if (idtable.table[lextable.table[i + index].idxTI].idDataType != IT::IDDATATYPE::CHAR)
								throw ERROR_THROW_IN(137, lextable.table[i + index].sn, 0);
						}
					}
					index++;
				}
			}
			break;

			default:
				break;
			}
		}
		if (lextable.table[i].lexema == LEX_CYCLE)
		{
			IT::IDDATATYPE leftType = idtable.table[lextable.table[i + 2].idxTI].idDataType;
			IT::IDDATATYPE rightType = idtable.table[lextable.table[i + 4].idxTI].idDataType;

			if (leftType == IT::IDDATATYPE::STR || rightType == IT::IDDATATYPE::STR)
			{
				throw ERROR_THROW_IN(606, lextable.table[i].sn, 0);
			}
			if (leftType == IT::IDDATATYPE::SHORT || rightType == IT::IDDATATYPE::SHORT)
			{
				if (!(lextable.table[i + 3].lexema == LEX_MORE || lextable.table[i + 3].lexema == LEX_LESS ||
					lextable.table[i + 3].lexema == LEX_MOREEQUAL || lextable.table[i + 3].lexema == LEX_LESSEQUAL ||
					lextable.table[i + 3].lexema == LEX_INEQUALITY || lextable.table[i + 3].lexema == LEX_NOTEQUALS))
					throw ERROR_THROW_IN(606, lextable.table[i].sn, 0);
			}
		}
	}
}

// Проверка количества параметров в функции и последующее ее добавленеи в таблицу
void FillFunctions(Functions& functions, IT::IdTable& idtable)
{
	for (int i = 0, j = 0; i < idtable.size; i++)
	{
		if (idtable.table[i].idType == IT::IDTYPE::F)
		{
			Entry temp = {};
			temp.index = i;
			while (idtable.table[i + 1].idType == IT::IDTYPE::P)
			{
				if (temp.countOfParam > MAX_FUNCTION_PARAMS_COUNT)
					throw ERROR_THROW_IN(138, idtable.table[i].idxfirstLE, 0)
					temp.types[temp.countOfParam] = idtable.table[i + 1].idDataType;
				temp.countOfParam++;
				i++;
			}
			Add(functions, temp);
		}
	}
}

// Проверка параметров и типов функции
void CheckFuncParam(Functions& functions, IT::IdTable& idtable, LT::LexTable& lextable)
{
	bool isOkey = false;
	for (int i = 0; i < functions.size; i++)
	{
		for (int j = 0; j < lextable.size; j++)
		{
			if (lextable.table[j].idxTI == functions.table[i].index)
			{
				Entry temp = {};
				for (int k = 1; lextable.table[j + k].lexema != LEX_RIGHTHESIS_CLOSE; k++)
				{
					if (lextable.table[j + k].lexema == LEX_IDENTIFIER || lextable.table[j + k].lexema == LEX_LITERAL)
					{
						if (temp.countOfParam > MAX_FUNCTION_PARAMS_COUNT)
							throw ERROR_THROW_IN(138, lextable.table[j].sn, 0);
						temp.types[temp.countOfParam] = idtable.table[lextable.table[j + k].idxTI].idDataType;
						temp.countOfParam++;
					}
				}
				if (!isEqual(temp, functions.table[i]))
					throw ERROR_THROW_IN(140, lextable.table[j].sn, 0);
			}
		}
	}
}

// Проверка параметров библиотечных функций
void CheckFuncParamCount(LT::LexTable& lextable, IT::IdTable& idtable)
{
	for (int i = 0; i < lextable.size; i++)
	{
		if (lextable.table[i].lexema == LEX_STRDUPLICATE ||
			lextable.table[i].lexema == LEX_STRLENGTH ||
			lextable.table[i].lexema == LEX_STRTRANSINT)
		{
			int countOfParam = 0;
			int index = i;
			while (lextable.table[i + 1].lexema != LEX_RIGHTHESIS_CLOSE)
			{
				if (lextable.table[i + 1].lexema == LEX_IDENTIFIER || lextable.table[i + 1].lexema == LEX_LITERAL)
				{
					if (idtable.table[lextable.table[i + 1].idxTI].idDataType != IT::IDDATATYPE::STR)
						throw ERROR_THROW_IN(141, lextable.table[i + 1].sn, 0);

					countOfParam++;
				}
				i++;
			}

			switch (lextable.table[index].lexema)
			{
			case LEX_STRDUPLICATE:
				if (countOfParam != 2)
					throw ERROR_THROW_IN(141, lextable.table[index].sn, 0);
				break;
			case LEX_STRLENGTH:
				if (countOfParam != 1)
					throw ERROR_THROW_IN(141, lextable.table[index].sn, 0);
				break;
			case LEX_STRTRANSINT:
				if (countOfParam != 1)
					throw ERROR_THROW_IN(141, lextable.table[index].sn, 0);
				break;
			default:
				break;
			}
		}
	}
}

// Проверка типа возвращаемого значения функции
void CheckReturnType(LT::LexTable& lextable, IT::IdTable& idtable)
{
	for (int i = 0; i < idtable.size; i++)
	{
		if (idtable.table[i].idType == IT::IDTYPE::F)
		{
			bool isReturn = false;
			for (int j = 1; j + idtable.table[i].idxfirstLE < lextable.size; j++)
			{
				if (lextable.table[idtable.table[i].idxfirstLE + j].lexema == LEX_RETURN)
				{
					if (idtable.table[lextable.table[idtable.table[i].idxfirstLE + j + 1].idxTI].idDataType != idtable.table[i].idDataType)
						throw ERROR_THROW_IN(145, lextable.table[idtable.table[i].idxfirstLE + j].sn, 0);
					isReturn = true;
				}
				if (lextable.table[idtable.table[i].idxfirstLE + j].lexema == LEX_FUNCTION || lextable.table[idtable.table[i].idxfirstLE + j].lexema == LEX_MAIN)
					break;
			}
			if (!isReturn)
				throw ERROR_THROW_IN(147, lextable.table[idtable.table[i].idxfirstLE].sn, 0);
		}
	}
}

// Создание таблицы функций
Functions Create(int size)
{
	if (size > MAX_FUNCTIONS_COUNT)
		throw ERROR_THROW(1);

	Functions functions;
	functions.maxsize = size;
	functions.size = 0;
	functions.table = new Entry[functions.maxsize];		// Массив строк функций

	return functions;
}

// Добавленеи функции в таблицу
void Add(Functions& functions, Entry entry)
{
	if (functions.size > functions.maxsize)
		throw ERROR_THROW(139);

	functions.table[functions.size] = entry;
	functions.size++;
}

// Равенство количества параметров вызываемой и объявленной функции
bool isEqual(Entry& entry1, Entry& entry2)
{
	if (entry1.countOfParam == entry2.countOfParam)
	{
		for (int i = 0; i < entry1.countOfParam; i++)
		{
			if (entry1.types[i] != entry2.types[i])
				return false;
		}
		return true;
	}
	else
		return false;
}
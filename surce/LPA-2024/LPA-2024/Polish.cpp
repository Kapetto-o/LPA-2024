#include "stdafx.h"
#include "Polish.h"

using namespace std;

namespace Polish
{
	void CallPolishNotation(LT::LexTable& lextable, IT::IdTable& idtable)
	{
		for (int i = 0; i < lextable.size; i++)
		{
			if (lextable.table[i].lexema == LEX_EQUALS && (idtable.table[lextable.table[i - 1].idxTI].idDataType != IT::IDDATATYPE::BOOL || idtable.table[lextable.table[i + 1].idxTI].idType == IT::IDTYPE::F))
			{
				polishNotation(++i, lextable, idtable);
			}
		}
	}

	void polishNotation(int lextable_pos, LT::LexTable& lextable, IT::IdTable& idtable)
	{
		queue<LT::Entry> queue;
		stack<LT::Entry> stack;
		LT::Entry forbidden = { '#', LT_TI_NULLTDX, LT_TI_NULLTDX };
		int countOfLex = 0;
		int posOfFirstLex = lextable_pos;

		// ‘ормирование польской записи в очереди, в стек помещаютс€ операторы и затем берутс€ из стека и помещаютс€ в очередь
		for (lextable_pos; lextable.table[lextable_pos].lexema != LEX_SEMICOLON; lextable_pos++, countOfLex++)
		{
			switch (lextable.table[lextable_pos].lexema)
			{
			case LEX_STRDUPLICATE:
			{
				stack.push(lextable.table[lextable_pos]);
				continue;
			}
			case LEX_STRLENGTH:
			{
				stack.push(lextable.table[lextable_pos]);
				continue;
			}
			case LEX_IDENTIFIER:
			{
				if (idtable.table[lextable.table[lextable_pos].idxTI].idType == IT::IDTYPE::F)
				{
					stack.push(lextable.table[lextable_pos]);
					continue;
				}
				queue.push(lextable.table[lextable_pos]);
				continue;
			}
			case LEX_LITERAL:
			{
				queue.push(lextable.table[lextable_pos]);
				continue;
			}
			case LEX_LEFTHESIS_OPEN:
			{
				stack.push(lextable.table[lextable_pos]);
				continue;
			}
			case LEX_RIGHTHESIS_CLOSE:
			{
				if (!stack.empty())
				{
					while (stack.top().lexema != LEX_LEFTHESIS_OPEN)
					{
						queue.push(stack.top());
						stack.pop();
					}
					stack.pop();
				}
				continue;
			}
			case LEX_ADDITION:
				if (!stack.empty())
				{
					while (priorityIs(lextable.table[lextable_pos]) <= priorityIs(stack.top()) || stack.top().lexema == 'p' || stack.top().lexema == 'a' || idtable.table[stack.top().idxTI].idType == IT::IDTYPE::F)
					{
						queue.push(stack.top());
						stack.pop();
						if (stack.empty())
							break;
					}
				}
				stack.push(lextable.table[lextable_pos]);
				continue;
			case LEX_SUBSTRACTION:
				if (!stack.empty())
				{
					while (priorityIs(lextable.table[lextable_pos]) <= priorityIs(stack.top()) || stack.top().lexema == 'p' || stack.top().lexema == 'a' || idtable.table[stack.top().idxTI].idType == IT::IDTYPE::F)
					{
						queue.push(stack.top());
						stack.pop();
						if (stack.empty())
							break;
					}
				}
				stack.push(lextable.table[lextable_pos]);
				continue;
			case LEX_MULTIPLICATION:
				if (!stack.empty())
				{
					while (priorityIs(lextable.table[lextable_pos]) <= priorityIs(stack.top()) || stack.top().lexema == 'p' || stack.top().lexema == 'a' || idtable.table[stack.top().idxTI].idType == IT::IDTYPE::F)
					{
						// помещаем в очередь оператор с вершины стэка
						queue.push(stack.top());	// в очереди находитс€ сама польска€ запись
						stack.pop();				// в стэке операторы

						if (stack.empty())
							break;
					}
				}
				stack.push(lextable.table[lextable_pos]);
				continue;
			case LEX_DIVISION:
				if (!stack.empty())
				{
					while (priorityIs(lextable.table[lextable_pos]) <= priorityIs(stack.top()) || stack.top().lexema == 'p' || stack.top().lexema == 'a' || idtable.table[stack.top().idxTI].idType == IT::IDTYPE::F)
					{
						queue.push(stack.top());
						stack.pop();
						if (stack.empty())
							break;
					}
				}
				stack.push(lextable.table[lextable_pos]);
				continue;
			case LEX_REMAINDERDIVISION:
				if (!stack.empty())
				{
					while (priorityIs(lextable.table[lextable_pos]) <= priorityIs(stack.top()) || stack.top().lexema == 'p' || stack.top().lexema == 'a' || idtable.table[stack.top().idxTI].idType == IT::IDTYPE::F)
					{
						queue.push(stack.top());
						stack.pop();
						if (stack.empty())
							break;
					}
				}
				stack.push(lextable.table[lextable_pos]);
				continue;
			case LEX_COMMA:
				while (stack.top().lexema != LEX_LEFTHESIS_OPEN)
				{
					queue.push(stack.top());
					stack.pop();
				}
				continue;
			default:
				continue;
			}
		}
		while (!stack.empty())
		{
			queue.push(stack.top());
			stack.pop();
		}

		// –азбор польской записи, лежащей в очереди
		for (int i = 0; i < countOfLex; i++)
		{
			if (!queue.empty())
			{
				switch (queue.front().lexema)
				{
				case LEX_IDENTIFIER:
					if (posOfFirstLex <= idtable.table[queue.front().idxTI].idxfirstLE && idtable.table[queue.front().idxTI].idxfirstLE < posOfFirstLex + countOfLex)
					{
						lextable.table[posOfFirstLex + i] = queue.front();
						idtable.table[queue.front().idxTI].idxfirstLE = posOfFirstLex + i;
						queue.pop();
					}
					else
					{
						lextable.table[posOfFirstLex + i] = queue.front();
						queue.pop();
					}
					continue;
				case LEX_LITERAL:
					lextable.table[posOfFirstLex + i] = queue.front();
					idtable.table[queue.front().idxTI].idxfirstLE = posOfFirstLex + i;
					queue.pop();
					continue;
				case LEX_STRDUPLICATE:
					lextable.table[posOfFirstLex + i] = queue.front();
					queue.pop();
					continue;
				case LEX_STRLENGTH:
					lextable.table[posOfFirstLex + i] = queue.front();
					queue.pop();
					continue;
				default:
					lextable.table[posOfFirstLex + i] = queue.front();
					queue.pop();
					continue;
				}
			}
			else
			{
				lextable.table[posOfFirstLex + i] = forbidden;
			}
		}
	}

	int priorityIs(LT::Entry entry)
	{
		switch (entry.lexema)
		{
		case LEX_LEFTHESIS_OPEN:
			return 0;
		case LEX_RIGHTHESIS_CLOSE:
			return 0;
		case LEX_COMMA:
			return 1;
		case LEX_ADDITION:
			return 2;
		case LEX_SUBSTRACTION:
			return 2;
		case LEX_MULTIPLICATION:
			return 3;
		case LEX_DIVISION:
			return 3;
		case LEX_REMAINDERDIVISION:
			return 3;
		default:
			return -1;
		}
	}
}
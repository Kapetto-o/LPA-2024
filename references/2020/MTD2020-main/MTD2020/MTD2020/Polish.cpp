#include "stdafx.h"
#include "LT.h"
#include <stack>
#include <queue>

using namespace std;

int search(int index, LEX::LexTable& ltable) //поиск выражения
{
	for (int i = index; i < (unsigned int)ltable.size; i++) //перебор лексем
	{
		if (ltable.table[i].lexema == LEX_PLUS || ltable.table[i].lexema == LEX_MINUS
			|| ltable.table[i].lexema == LEX_STAR || ltable.table[i].lexema == LEX_DIRSLASH
			|| ltable.table[i].lexema == LEX_AND || ltable.table[i].lexema == LEX_OR
			|| ltable.table[i].lexema == LEX_NOT) //находим операцию
		{
			for (; ; i--) //перебираем лексемы обратно
			{
				if (ltable.table[i].lexema == LEX_COMPARE || ltable.table[i].lexema == LEX_RIGHTHESIS)
					return i + 1;
			}
		}
	}
	return -1; //если не нашли возвращаем минус 1
}



bool PolishNotation(LEX::LexTable& ltable, ID::IdTable& itable)
{
	stack<LEX::Entry> stack;	  	// стек для операций
	queue<LEX::Entry> queue;	 	// очередь для операндов
	LEX::Entry temp;				//  все лишние элементы будут заменяться на эту лексему
	temp.indxTI = -1;               // индекс в таблице id
	temp.lexema = '$';
	int i = 0;						// количество преобразованных лексем
	int posLex;						// запоминаем номер лексемы перед преобразованием
	while (search(i, ltable) != -1) {

		i = search(i, ltable);
		int countLex = 0;
		posLex = i;
		while (ltable.table[i].lexema != LEX_POINT) {
			if (ltable.table[i].lexema == LEX_ID)			// если идентификатор
			{
				queue.push(ltable.table[i]);
			}
			if (ltable.table[i].lexema == LEX_LITERAL)		// если литерал
			{
				queue.push(ltable.table[i]);				// помещаем в очередь
			}
			if (ltable.table[i].lexema == LEX_LEFTHESIS)	// если (
			{
				stack.push(ltable.table[i]);				// помещаем ее в стек
			}
			if (ltable.table[i].lexema == LEX_RIGHTHESIS)	// если )
			{
				while (stack.top().lexema != LEX_LEFTHESIS)	// пока не встретим (
				{
					queue.push(stack.top());				// выталкиваем со стека в очередь
					stack.pop();

					if (stack.empty())
						return false;
				}
				stack.pop();	// уничтожаем (
			}
			if (ltable.table[i].lexema == LEX_PLUS ||
				ltable.table[i].lexema == LEX_MINUS ||
				ltable.table[i].lexema == LEX_STAR ||
				ltable.table[i].lexema == LEX_DIRSLASH ||
				ltable.table[i].lexema == LEX_AND ||
				ltable.table[i].lexema == LEX_OR ||
				ltable.table[i].lexema == LEX_NOT)	// если знак оператора
			{
				while (!stack.empty() && ltable.table[i].priority <= stack.top().priority)	// пока приоритет текущего оператора 
																									//меньше или равен приоритету оператора в вершине стека
				{
					queue.push(stack.top());	// выталкиваем со стека в выходную строку
					stack.pop();
				}
				stack.push(ltable.table[i]);
			}
			i++; countLex++;
		}
		while (!stack.empty())	// если стек не пустой
		{
			if (stack.top().lexema == LEX_LEFTHESIS || stack.top().lexema == LEX_RIGHTHESIS)
				return false;
			queue.push(stack.top());	// выталкиваем все в очередь
			stack.pop();
		}
		while (countLex != 0)		// замена текущего выражения в таблице лексем на выражение в ПОЛИЗ
		{
			if (!queue.empty()) {
				ltable.table[posLex++] = queue.front();
				queue.pop();
			}
			else
			{
				temp.sn = ltable.table[i].sn;
				ltable.table[posLex++] = temp;			// перезапишем символы
			}
			countLex--;
		}
		for (int i = 0; i < posLex; i++)		// восстановление индексов первого вхождения в таблицу лексем у операторов из таблицы идентификаторов
		{
			if (ltable.table[i].lexema == LEX_PLUS || ltable.table[i].lexema == LEX_MINUS || ltable.table[i].lexema == LEX_STAR || ltable.table[i].lexema == LEX_DIRSLASH || ltable.table[i].lexema == LEX_LITERAL || ltable.table[i].lexema == LEX_AND || ltable.table[i].lexema == LEX_OR || ltable.table[i].lexema == LEX_NOT)
				itable.table[ltable.table[i].indxTI].idxfirstLE = i;
		}
	}
	return true;
}
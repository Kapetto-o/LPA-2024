#include "stdafx.h"
//синтакс
#define GRB_ERROR_SERIES 100

namespace GRB
{
	Greibach greibach(NS('S'), TS('$'), 
		8,		
		Rule(NS('S'), GRB_ERROR_SERIES, 5,   // структура программы
			Rule::Chain(10, TS('c'), TS('f'), TS('i'), TS('('), NS('P'), TS(')'), TS('{'), NS('K'), TS('}'), NS('S')),
			Rule::Chain(10, TS('n'), TS('f'), TS('i'), TS('('), NS('P'), TS(')'), TS('{'), NS('K'), TS('}'), NS('S')),
			Rule::Chain(9, TS('c'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('K'), TS('}'), NS('S')),
			Rule::Chain(9, TS('n'), TS('f'), TS('i'), TS('('), TS(')'), TS('{'), NS('K'), TS('}'), NS('S')),
			Rule::Chain(4, TS('m'), TS('{'), NS('K'), TS('}'))
		),
		Rule(NS('P'), GRB_ERROR_SERIES + 1, 4, //параметры функции
			Rule::Chain(4, TS('s'), TS('i'), TS(','), NS('P')),
			Rule::Chain(2, TS('s'), TS('i')),
			Rule::Chain(4, TS('n'), TS('i'), TS(','), NS('P')),
			Rule::Chain(2, TS('n'), TS('i'))
		),
		Rule(NS('K'), GRB_ERROR_SERIES + 2, 19,  // синтаксические конструкции
			Rule::Chain(5, TS('t'), TS('n'), TS('i'), TS(';'), NS('K')),
			Rule::Chain(5, TS('t'), TS('c'), TS('i'), TS(';'), NS('K')),
			Rule::Chain(7, TS('t'), TS('n'), TS('i'), TS('='), NS('E'), TS(';'), NS('K')),
			Rule::Chain(7, TS('t'), TS('c'), TS('i'), TS('='), NS('E'), TS(';'), NS('K')),
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('K')),
			Rule::Chain(4, TS('o'), NS('E'), TS(';'), NS('K')),
			
			Rule::Chain(3, TS('r'), TS('i'), TS(';')),
			Rule::Chain(3, TS('r'), TS('l'), TS(';')),
			Rule::Chain(4, TS('t'), TS('n'), TS('i'), TS(';')),
			Rule::Chain(4, TS('t'), TS('c'), TS('i'), TS(';')),
			Rule::Chain(6, TS('t'), TS('n'), TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(6, TS('t'), TS('c'), TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(3, TS('o'), NS('E'), TS(';')),
			Rule::Chain(6, TS('a'), TS('('), NS('W'), TS(')'), TS(';'), NS('K')),

			Rule::Chain(10, TS('u'), TS('('), TS('i'), NS('L'), TS('i'), TS(')'), TS('{'), NS('E'), TS('}'), NS('K')),
			Rule::Chain(9, TS('u'), TS('('), TS('i'), NS('L'), TS('i'), TS(')'), TS('{'), NS('E'), TS('}')),
			Rule::Chain(10, TS('u'), TS('('), TS('i'), NS('L'), TS('l'), TS(')'), TS('{'), NS('E'), TS('}'), NS('K')),
			Rule::Chain(9, TS('u'), TS('('), TS('i'), NS('L'), TS('l'), TS(')'), TS('{'), NS('E'), TS('}'))
		
		),
		Rule(NS('E'), GRB_ERROR_SERIES + 3, 22, //выражения
			Rule::Chain(1, TS('i')),
			Rule::Chain(2, TS('i'), NS('E')),
			Rule::Chain(2, TS('i'), TS(';')),
			Rule::Chain(3, TS('i'), TS(';'), NS('E')),
			Rule::Chain(5, TS('i'), TS('='), TS('i'), NS('A'), NS('E')),
			Rule::Chain(4, TS('i'), TS('='), TS('i'), NS('A')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(2, TS('l'), NS('E')),
			Rule::Chain(2, TS('l'), TS(';')),
			Rule::Chain(2, TS('i'), NS('A')),
			Rule::Chain(2, TS('l'), NS('A')),

			Rule::Chain(3, TS('('), NS('W'), TS(')')),
			Rule::Chain(4, TS('('), NS('W'), TS(')'), NS('A')),
			Rule::Chain(4, TS('('), NS('E'), TS(')'), NS('A')),
			Rule::Chain(3, TS('i'), TS('('), TS(')')),
			Rule::Chain(4, TS('i'), TS('('), TS(')'), NS('A')),

			Rule::Chain(4, TS('p'), TS('('), NS('W'), TS(')')),
			Rule::Chain(5, TS('p'), TS('('), NS('W'), TS(')'), NS('A')),
			Rule::Chain(4, TS('a'), TS('('), NS('W'), TS(')')),
			Rule::Chain(5, TS('a'), TS('('), NS('W'), TS(')'), NS('A')),

			Rule::Chain(6, TS('o'), TS('('), TS('i'), TS(')'), TS(';'), NS('E')),
			Rule::Chain(5, TS('o'), TS('('), TS('i'), TS(')'), TS(';'))

		),
		Rule(NS('W'), GRB_ERROR_SERIES + 4, 4, //принимаемые параметры функции
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('i'), TS(','), NS('W')),
			Rule::Chain(3, TS('l'), TS(','), NS('W'))
		),
		Rule(NS('A'), GRB_ERROR_SERIES + 5, 4, // арифметич знаки
			Rule::Chain(2, TS('+'), NS('E')),
			Rule::Chain(2, TS('-'), NS('E')),
			Rule::Chain(2, TS('*'), NS('E')),
			Rule::Chain(2, TS('/'), NS('E'))
		),

		Rule(NS('L'), GRB_ERROR_SERIES + 6, 6, // логич знаки
			Rule::Chain(1, TS('<')),
			Rule::Chain(1, TS('>')),
			Rule::Chain(1, TS('!')),
			Rule::Chain(1, TS('&')),
			Rule::Chain(1, TS(']')),
			Rule::Chain(1, TS('['))
		),
		
		Rule(NS('С'), GRB_ERROR_SERIES + 7, 8, // цикл
			Rule::Chain(5, TS('i'), TS('='), NS('E'), TS(';'), NS('C')),
			Rule::Chain(4, TS('o'), TS('i'), TS(';'), NS('C')),
			Rule::Chain(4, TS('o'), TS('l'), TS(';'), NS('C')),
			Rule::Chain(6, TS('i'), TS('('), NS('W'), TS(')'), TS(';'), NS('C')),

			Rule::Chain(4, TS('i'), TS('='), NS('E'), TS(';')),
			Rule::Chain(3, TS('o'), TS('i'), TS(';')),
			Rule::Chain(3, TS('o'), TS('l'), TS(';')),
			Rule::Chain(5, TS('i'), TS('('), NS('W'), TS(')'), TS(';'))
			
		)
			
	);

	Rule::Chain::Chain(short psize, GRBALPHABET s, ...)  //конструктор цепочки - правой части правила(кол-во символов в цепочке, терминал или нетерминал...)
	{
		nt = new GRBALPHABET[size = psize];    //цепочка терминалов
		int* p = (int*)&s;                      //присваиваем символ указателю п
		for (short i = 0; i < psize; ++i)
			nt[i] = (GRBALPHABET)p[i]; //заполняем цепочку терминалов
	};

	Rule::Rule(GRBALPHABET pnn, int piderror, short psize, Chain c, ...) //конструктор правила
	{															//(нетерминал, идентификатор диагностического сообщения, количество цепочек(правых частей правила), множество цепочек (правых частей правила)
		nn = pnn;    //нетерминал
		iderror = piderror; //идентификатор
		chains = new Chain[size = psize]; //место для цепочки
		Chain* p = &c;
		for (int i = 0; i < size; i++)
			chains[i] = p[i]; //заполняем множество цепочек
	};

	Greibach::Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottom, short psize, Rule r, ...)//конструктор гграматики Грейбаха(стартовый символ, дно стека, количество правил, правила...)
	{
		startN = pstartN; //стартовый символ
		stbottomT = pstbottom;//дно стека
		rules = new Rule[size = psize];//выделяем память
		Rule* p = &r;
		for (int i = 0; i < size; i++) rules[i] = p[i];//заполняем правила
	};
	Greibach getGreibach() { return greibach; }; //получить грамматику

	short Greibach::getRule(GRBALPHABET pnn, Rule& prule) //получить правило (левый символ правила, возвращаемое правило грамматики)
	{
		short rc = -1;
		short k = 0;
		while (k < size && rules[k].nn != pnn)
			k++;   //пока К меньше количества правил и пока левый символ правила не равен парметру ф-ции
		if (k < size)
			prule = rules[rc = k];    //возвращаемое правило граматики равно правилу с индексом К
		return rc; //возвращается номер правила или -1
	};

	Rule Greibach::getRule(short n) //получить правило по номеру
	{
		Rule rc;      //создаём правило рц
		if (n < size)rc = rules[n];  //присваиваем правилу рц правило н
		return rc; //возвращаем созданное правило
	};

	char* Rule::getCRule(char* b, short nchain) //получить правило в виде N->цепочка (буфер, номер цепочки(правой части) в правиле)
	{
		char bchain[200]; //строка
		b[0] = Chain::alphabet_to_char(nn); b[1] = '-'; b[2] = '>'; b[3] = 0x00; //терминал -> 
		chains[nchain].getCChain(bchain); //получает правую сторонц правила
		strcat_s(b, sizeof(bchain) + 5, bchain);//добавляем строку (куда, с какого элемента, строку)
		return b;
	};

	short Rule::getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j) //получить следующую за j подходящую цепочку, вернуть её номер или -1 
	{                                                                //(первый символ цепочки, возвращаемая цепочка, номер цепочки)
		short rc = -1;
		while (j < size && chains[j].nt[0] != t)++j;
		rc = (j < size ? j : -1);
		if (rc >= 0)pchain = chains[rc];
		return rc;
	};

	char* Rule::Chain::getCChain(char* b) //получить правую сторону правила
	{
		for (int i = 0; i < size; i++)b[i] = Chain::alphabet_to_char(nt[i]);
		b[size] = 0x00;
		return b;
	};
};
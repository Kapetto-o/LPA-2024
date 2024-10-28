#include "stdafx.h"
#include"Rule.h"
using namespace GRB;
namespace GRB
{
	Rule::Chain::Chain(short psize, GRBALPHABET s, ...)			//конструктор цепочки - правой части правила(кол-во символов в цепочке, терминал или нетерминал...)
	{
		nt = new GRBALPHABET[size = psize];		  //цепочка терминалов
		int* p = (int*)&s;						  //присваиваем символ указателю п
		for (short i = 0; i < psize; i++)
			nt[i] = (GRBALPHABET)p[i];			  //заполняем цепочку терминалов
	}

	Rule::Rule(GRBALPHABET pnn, int piderror, short psize, Chain c, ...)	//конструктор правила
	{												//(нетерминал, идентификатор диагностического сообщения, количество цепочек(правых частей правила), множество цепочек (правых частей правила)
		nn = pnn;					//нетерминал
		iderror = piderror;			//идентификатор
		chains = new Chain[size = psize];			//место для цепочки
		Chain* p = &c;
		for (int i = 0; i < size; i++)
			chains[i] = p[i];		//заполняем множество цепочек
	}

	Greibach::Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottom, short psize, Rule r, ...)//конструктор гграматики Грейбаха(стартовый символ, дно стека, количество правил, правила...)
	{
		startN = pstartN;		//стартовый символ
		stbottomT = pstbottom;	//дно стека
		rules = new Rule[size = psize];
		Rule* p = &r;
		for (int i = 0; i < size; i++)
			rules[i] = p[i];		//заполняем правила
	}

	Greibach getGreibach()
	{
		return greibach;		//получить грамматику
	}

	short Greibach::getRule(GRBALPHABET pnn, Rule& prule)	//получить правило (левый символ правила, возвращаемое правило грамматики)
	{
		short rc = -1;
		short k = 0;
		while (k < size && rules[k].nn != pnn)
			k++;			//пока К меньше количества правил и пока левый символ правила не равен парметру ф-ции
		if (k < size)
			prule = rules[rc = k];		 //возвращаемое правило граматики равно правилу с индексом К
		return rc;			//возвращается номер правила или -1
	}

	Rule Greibach::getRule(short n)			//получить правило по номеру
	{
		Rule rc;			 //создаём правило рц
		if (n < size)
			rc = rules[n];	//присваиваем правилу рц правило н
		return rc;			//возвращаем созданное правило
	}

	char* Rule::getCRule(char* b, short nchain)					// Получить правило в виде N -> цепочка
	{
		char bchain[200];
		b[0] = Chain::alphabet_to_char(nn);		//терминал -> 
		b[1] = '-';
		b[2] = '>';
		b[3] = 0x00;
		chains[nchain].getCChain(bchain);		//получает правую сторонц правила
		strcat_s(b, sizeof(bchain) + 5, bchain);//добавляем строку (куда, с какого элемента, строку)
		return b;
	}

	short Rule::getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j)	//получить следующую за j подходящую цепочку, вернуть её номер или -1 
	{									//(первый символ цепочки, возвращаемая цепочка, номер цепочки)
		short rc = -1;
		while (j < size && chains[j].nt[0] != t)
			++j;
		rc = (j < size ? j : -1);
		if (rc >= 0)
			pchain = chains[rc];
		return rc;
	}

	char* Rule::Chain::getCChain(char* b)		//получить правую сторону правила
	{
		for (int i = 0; i < size; i++)
			b[i] = Chain::alphabet_to_char(nt[i]);
		b[size] = 0x00;
		return b;
	}
}
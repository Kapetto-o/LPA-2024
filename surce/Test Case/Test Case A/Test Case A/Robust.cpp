﻿int function testfunc1(int a, int b)
{
	new int res = a + b;
	return res;
};

str function testfunc2(str parm1)
{
	new str parm2 = "TestText20";

	strduplicate(parm1, parm2);		// Копирование строки parm2 в parm1

	return parm1;
};
char function testfunc3(char simbol)
{
	new int i = 0;
	cycle(i < 10) {
		write simbol;
		i = i + 1;
	}
}
bool function testfunc4(int chetnoe)
{
	return chetnoe % 2 == 0;
}
main
{
	writeline "Арифметические операции:";

	new int a;
	new int b = 15;

	a = 10 * 5;		// Умножение
	write a;
	a = 10 / 5;		// Деление
	write a;
	a = 15 % 10;	// Деление с остатком
	write a;
	a = 10 + 5;		// Сумма
	write a;
	a = 10 - 5;		// Разница
	write a;

	writeline "Вызов функций:";

	// Пользовательские функции:

	new int number = testfunc1(0, 5);
	write number;

	new str parm1 = "TestText1";
	new str string = testfunc2(parm1);
	writeline string;

	new char alpha = 'a';
	testfunc3(alpha);

	new int myint = 120;
	new bool pravda = testfunc4(myint);
	writeline pravda;

	// Библиотечные функции:

	new str stroka = "Тестовая строчка";
	new str strokachislo = "125";

	strduplicate(copystr, stroka);		// Копирование строки stroka в copystr
	writeline copystr;

	new int dlina = strlength(stroka);	// Вычисление длины строки stroka
	writeline dlina;

	new int testint = strtransint(strokachislo);
	new int testint2 = 5 + testint;
	writeline testint2;

	writeline "Цикл:";

	new int i = 0;

	cycle(i < 10)
	{
		write i;
		i = i + 1;
	}
}
int function testfunc1(int a, int b)
{
	new int res = a + b;
	return res;
};

str function testfunc1(str parm1)		// Ошибка 130 (существующий идентификатор функции)
{
	new str parm2 = "TestText20";

	strcopy(parm1, parm2);		// Копирование строки parm2 в parm1

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
	new str c = "text";
	
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

	int number = testfunc1(0, 5);
	write number;

	str parm1 = "TestText1";
	str string = testfunc1(parm1);
	writeline string;

	char alpha = 'a';
	testfunc3(alpha);

	int myint = 120;
	bool pravda = testfunc4(myint);
	writeline pravda;

	// Библиотечные функции:

	str stroka = "Тестовая строчка";
	str strokachislo = "125";

	strcopy(copystr, stroka);		// Копирование строки stroka в copystr
	writeline copystr;

	int dlina = strlength(stroka);	// Вычисление длины строки stroka
	writeline dlina;

	int testint = strtransint(strokachislo);
	int testint2 = 5 + testint;
	writeline testint2;

	writeline "Цикл:";

	int i = 0;

	cycle(i < 10)
	{
		write i;
		i = i + 1;
	}
}
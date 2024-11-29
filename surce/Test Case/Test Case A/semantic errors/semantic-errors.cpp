int testfunc1(int a, int b)
{
	int res = a + b;
	return res;
};

str testfunc1(str parm1)		// Ошибка 130 (существующий идентификатор функции)
{
	str parm2 = "TestText20";

	strcopy(parm1, parm2);		// Копирование строки parm2 в parm1

	return parm1;
};
char testfunc3(char simbol)
{
	int i = 0;
	cycle(i < 10) {
		write simbol;
		i = i + 1;
	}
}
bool testfunc4(int chetnoe)
{
	return chetnoe % 2 == 0;
}
main
{
	writeline "Арифметические операции:";

	int a;
	int b = 15;					
	str c = "text";
	
	int a = 10 * 5;	// Умножение. Ошибка 131 (повторное объявление идентификатора)
	write a;
	a = 10 / 5;		// Деление
	write a;
	a = 15 % 10;	// Деление с остатком
	write a;
	a = 10 + 5;		// Сумма
	write a;
	a = 10 - 5;		// Разница
	write a;

	d = c + 10;		// Ошибка 132 (оператор не предназначен для работы со строками

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
int testintfunction (int a, int b)
{
	int res = -1;
	cycle(a <= b)
	{
		res = res + 1;
		a = a + 1;
	}
	return res;
};

str teststrfunction (str parm1)
{
	str parm2 = "TestText20";

	strcopy(parm1, parm2);		// Копирование строки parm2 в parm1

	return parm1;
};

main
{
	writeline "Арифметические операции:";
	int a;

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

	int number = testintfunction(0, 5);
	write number;

	str parm1 = "TestText1";
	str string = teststrfunction(parm1);
	writeline string;

	int count = strtransint(string);

	writeline "Цикл:";
	int i = 0;

	cycle(i < 10)
	{
		write i;
		i = i + 1;
	}
}
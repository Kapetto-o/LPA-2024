int testfunc1(int a, int b)
{
	int res = a + b;
	return res;
};

str testfunc1(str parm1)		// ������ 130 (������������ ������������� �������)
{
	str parm2 = "TestText20";

	strcopy(parm1, parm2);		// ����������� ������ parm2 � parm1

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
	writeline "�������������� ��������:";

	int a;
	int b = 15;					
	str c = "text";
	
	int a = 10 * 5;	// ���������. ������ 131 (��������� ���������� ��������������)
	write a;
	a = 10 / 5;		// �������
	write a;
	a = 15 % 10;	// ������� � ��������
	write a;
	a = 10 + 5;		// �����
	write a;
	a = 10 - 5;		// �������
	write a;

	d = c + 10;		// ������ 132 (�������� �� ������������ ��� ������ �� ��������

	writeline "����� �������:";

	// ���������������� �������:

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

	// ������������ �������:

	str stroka = "�������� �������";
	str strokachislo = "125";

	strcopy(copystr, stroka);		// ����������� ������ stroka � copystr
	writeline copystr;

	int dlina = strlength(stroka);	// ���������� ����� ������ stroka
	writeline dlina;

	int testint = strtransint(strokachislo);
	int testint2 = 5 + testint;
	writeline testint2;

	writeline "����:";

	int i = 0;

	cycle(i < 10)
	{
		write i;
		i = i + 1;
	}
}
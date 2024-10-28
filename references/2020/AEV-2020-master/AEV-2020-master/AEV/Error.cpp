#include "stdafx.h"

namespace Error
{ //	0   -  9   -  ���������
	//	10  -  49  -  ������� ����������
	//	50  -  89  -  �������� � ������ ������
	//	90  -  99  -  ������ ������������ �������
	//  100 -  299  - ������ ��������������� �������
	//  300  - 399  - ������ �������������� �������
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "[SYSTEM] ������������ ��� ������"), // ��� ������ ��� ��������� 0 - ERROR_MAX_ENTRY
		ERROR_ENTRY(1, "[SYSTEM] ��������� ����"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY(10, "[PARM] �������� -in ������ ���� �����"),
		ERROR_ENTRY(11, "[PARM] ��������� ����� �������� ���������"),
		ERROR_ENTRY_NODEF(12), ERROR_ENTRY_NODEF(13), ERROR_ENTRY_NODEF(14), ERROR_ENTRY_NODEF(15),
		ERROR_ENTRY_NODEF(16), ERROR_ENTRY_NODEF(17), ERROR_ENTRY_NODEF(18), ERROR_ENTRY_NODEF(19),
		ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY(50, "[FILE] ������ ��� �������� ����� � �������� �����(-in)"),
		ERROR_ENTRY(51, "[FILE] ������������ ������ � �������� ����� (-in)"),
		ERROR_ENTRY(52, "[FILE] ������ ��� �������� ����� ���������(-log)"),
		ERROR_ENTRY(53, "[PARM] ���������� ����������� ������� � ��������� ��������"),
		ERROR_ENTRY_NODEF(54),
		ERROR_ENTRY_NODEF(55), 
		ERROR_ENTRY_NODEF(56), 	ERROR_ENTRY_NODEF(57), ERROR_ENTRY_NODEF(58), ERROR_ENTRY_NODEF(59),
		ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), 
		ERROR_ENTRY(90, "[LEX] �������� ������ ������� ���������������"),
		ERROR_ENTRY(91, "[LEX] �������� ������ ������� ������"),
		ERROR_ENTRY(92, "[LEX] C���� �� ���������"),
		ERROR_ENTRY(93, "[LEX] ������������ ������������� ������ �������������� �������� ��� �������� ������������"), //�� ����� ����
		ERROR_ENTRY(94, "[LEX] � ���������� ���������� �� ����� ���� ������ ������ �������"), 
		ERROR_ENTRY_NODEF(95), ERROR_ENTRY_NODEF(96),
		ERROR_ENTRY_NODEF(97), ERROR_ENTRY_NODEF(98), ERROR_ENTRY_NODEF(99),
		ERROR_ENTRY(100, "[SYN] �������� ��������� ���������"),
		ERROR_ENTRY(101, "[SYN] ������ � ���������� �������"),
		ERROR_ENTRY(102, "[SYN] ��������� �����������"),
		ERROR_ENTRY(103, "[SYN] ������ � ���������"),
		ERROR_ENTRY(104, "[SYN] ������ � ���������� ���������� �������"),
		ERROR_ENTRY(105, "[SYN] ������ � ���������� ��������������� ���������"),
		ERROR_ENTRY(106, "[SYN] ������ � ���������� ����������� ���������"), 
		ERROR_ENTRY(107, "[SYN] ������ � ���� �����"),
		ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109), ERROR_ENTRY_NODEF10(110),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140),
		ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170),
		ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF10(200),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240),
		ERROR_ENTRY_NODEF10(250),  ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280),
		ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY(300, "[SEM] ��������� ������������ ���������� ���������� ��� ������ �������"),
		ERROR_ENTRY(301, "[SEM] ������� ��������������� ��������������"),
		ERROR_ENTRY(302, "[SEM] ����������� ���������� ��������������"),
		ERROR_ENTRY(303, "[SEM] ����������� ����� ����� main"),
		ERROR_ENTRY(304, "[SEM] ����� ����� main ������ ���� ������������"),
		ERROR_ENTRY(305, "[SEM] �������������� �����"),
		ERROR_ENTRY(306, "[SEM] ��������� ����������� �������� �������"),
		ERROR_ENTRY(307, "[SEM] ��������� ������ �� ����"),
		ERROR_ENTRY(308, "[SEM] ������������� ����������� ������� ��� ����������� ����������� ����������"),
		ERROR_ENTRY(309, "[SEM] ������� ���������� ����������� ���������� ����� ������ ����"),
		ERROR_ENTRY(310, "[SEM] ������� ���������� �������� �� ��������� ����� ������"),
		ERROR_ENTRY(311, "[SEM] ��� ������������� �������� � ��� ������� �� ���������"),
		ERROR_ENTRY(312, "[SEM] ������������ ���������� ���������� ��� ������ �������"),
		ERROR_ENTRY(313, "[SEM] ������������ ��� ���������� ��� ������ �������"),
		ERROR_ENTRY(314, "[SEM] ��������� ���������� ���������� ���������� �������"),
		ERROR_ENTRY(315, "[SEM] ������������ ����� �������"),
		ERROR_ENTRY_NODEF(316), ERROR_ENTRY_NODEF(317), ERROR_ENTRY_NODEF(318), ERROR_ENTRY_NODEF(319)
	};


	ERROR GetError(int id)
	{
		if (id < 0 || id > ERROR_MAX_ENTRY)
			return errors[0];
		else
			return errors[id];
	}

	ERROR GetError(int id, int line, int col)
	{
		ERROR dopError = GetError(id);
		dopError.position.col = col;
		dopError.position.line = line;
		return dopError;
	}
}
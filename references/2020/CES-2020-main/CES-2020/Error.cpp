#include "stdafx.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		//	 0 - 99  -  ��������� ������ 
		ERROR_ENTRY(0, "������������ ��� ������"),
		ERROR_ENTRY(1, "[System] ��������� ����"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30),
		ERROR_ENTRY_NODEF10(40), ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60),
		ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		//			  100 - 109 -  ������ ����������
		ERROR_ENTRY(100, "[PARM] ������ ���������. �������� -in ������ ���� �����"),
		ERROR_ENTRY(101, "[PARM] ������ ���������. ��������� ����� �������� ���������"),
		ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103), ERROR_ENTRY_NODEF(104), ERROR_ENTRY_NODEF(105),
		ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107), ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		//		      110 - 119 -  ������ �������� � ������ ������
		ERROR_ENTRY(110, "[IN] ������ ��� �������� ����� � �������� ����� (/in)"),
		ERROR_ENTRY(111, "[IN] ������������ ������ � �������� ����� (/in)"),
		ERROR_ENTRY(112, "[IN] ������ ��� �������� ����� ���������"),
		ERROR_ENTRY(113, "[IN] ������ � ������ ���������� ��������"),
		ERROR_ENTRY(114, "[IN] ��������� ����� ����� � �������� �����"),
		ERROR_ENTRY(115, "[IN] ��������� ������������ ����� ����� � ����� � �������� �����"),
		ERROR_ENTRY_NODEF(116),
		ERROR_ENTRY_NODEF(117), ERROR_ENTRY_NODEF(118), ERROR_ENTRY_NODEF(119),
		//			  120 - 199  -  ������ ������������ �������
		ERROR_ENTRY(120, "[LexA] ������� �������� �� ���������"),
		ERROR_ENTRY(121, "[LexA] ������������ ������� ������"),
		ERROR_ENTRY(122, "[LexA] ������������ ������� ���������������"),
		ERROR_ENTRY_NODEF(123),
		ERROR_ENTRY_NODEF(124),
		ERROR_ENTRY_NODEF(125), ERROR_ENTRY_NODEF(126),
		ERROR_ENTRY_NODEF(127), ERROR_ENTRY_NODEF(128), ERROR_ENTRY_NODEF(129),
		ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		//			  200 - 299  -  ������ ��������������� �������
		ERROR_ENTRY(200, "[SynA] �������� ��������� ���������"),
		ERROR_ENTRY(201, "[SynA] ��������� ���������"),
		ERROR_ENTRY(202, "[SynA] ������ � ���������"),
		ERROR_ENTRY(203, "[SynA] ������ � ���������� �������"),
		ERROR_ENTRY(204, "[SynA] ������ � ���������� ���������� �������"),
		ERROR_ENTRY(205, "[SynA] ������ � �������� ���������"),
		ERROR_ENTRY(206, "[SynA] �������������� ������ �������� � ��������(����������� � log)"),
		ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208),
		ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210),ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230),
		ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250), ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270),
		ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		//  		  300 - 399  -  ������ �������������� �������
		ERROR_ENTRY(300, "[SemA] ��������������� ��������������"),
		ERROR_ENTRY(301, "[SemA] �������������� ������������� �������� ������� � � �����"),
		ERROR_ENTRY(302, "[SemA] �������� �������� ���� ����������"),
		ERROR_ENTRY(303, "[SemA] ������� �� 0 � ���������"),
		ERROR_ENTRY(304, "[SemA] ����� ������� �� � ����� �����"),
		ERROR_ENTRY(305, "[SemA] ��������� ������������ ���������� ������� � ���������"),
		ERROR_ENTRY(306, "[SemA] ������������� �������������"),
		ERROR_ENTRY(307, "[SemA] �������������� ����� � ��������� ������������"),
		ERROR_ENTRY(308, "[SemA] ����� ����� ������� ������� HEAD"),
		ERROR_ENTRY(309, "[SemA] ��� ���������������� ������� �� ������ ��������� � ������ ������� CESlib"),
		ERROR_ENTRY(310, "[SemA] ���������� ������� ������� HEAD"),
		ERROR_ENTRY(311, "[SemA] ���������� �������������� ��� ��� �������������"),
		ERROR_ENTRY(312, "[SemA] ���������� ������ ����� ���������� � ����� ���������"), 
		ERROR_ENTRY(313, "[SemA] ��������� ������������ ���������� ���������� � �������"),
		ERROR_ENTRY(314, "[SemA] �������� �������������� �������� �� ������ � �������� ���������� ��������"),
		ERROR_ENTRY(315, "[SemA] ��������� ������������ ����� ���������� ��������"),
		ERROR_ENTRY(316, "[SemA] �������������� ��������� � ���������"),
		ERROR_ENTRY(317, "[SemA] �������� ��������� � �������� �����������"),
		ERROR_ENTRY(318, "[SemA] �������� �������� ���������� ����������"),
		ERROR_ENTRY_NODEF(319),
		ERROR_ENTRY_NODEF(320),
		ERROR_ENTRY_NODEF(321),
		ERROR_ENTRY_NODEF(322),
		ERROR_ENTRY_NODEF(323),
		ERROR_ENTRY_NODEF(324),
		ERROR_ENTRY_NODEF(325), ERROR_ENTRY_NODEF(326), ERROR_ENTRY_NODEF(327), ERROR_ENTRY_NODEF(328),
		ERROR_ENTRY_NODEF(329),
		ERROR_ENTRY_NODEF10(330),
		ERROR_ENTRY_NODEF10(340), ERROR_ENTRY_NODEF10(350), ERROR_ENTRY_NODEF10(360),
		ERROR_ENTRY_NODEF10(370), ERROR_ENTRY_NODEF10(380), ERROR_ENTRY_NODEF10(390),

		ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500), ERROR_ENTRY_NODEF100(600),

		ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};

	ERROR geterror(int id) {
		if (id < 0 || id > ERROR_MAX_ENTRY)
			return errors[0];
		return errors[id];
	}
	ERROR geterrorin(int id, int line = -1, int col = -1) {
		if (id < 0 || id > ERROR_MAX_ENTRY)
			return errors[0];
		errors[id].inext.line = line;
		errors[id].inext.col = col;
		return errors[id];
	}
}
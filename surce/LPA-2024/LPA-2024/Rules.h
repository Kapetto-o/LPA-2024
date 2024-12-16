#pragma once
#include "Greibach.h"

#define GRB_ERROR_SERIES 600
#define NS(n)	GRB::Rule::Chain::N(n)
#define TS(n)	GRB::Rule::Chain::T(n)
#define ISNS(n)	GRB::Rule::Chain::isN(n)

namespace GRB
{
	Greibach greibach(
		NS('S'), TS('$'),
		9,
		Rule(
			NS('S'), GRB_ERROR_SERIES + 0,    // �������� ��������� ���������
			18,
			Rule::Chain(5, TS(LEX_MAIN), TS('{'), NS('N'), TS('}'), TS(';')),
			Rule::Chain(6, TS(LEX_MAIN), TS('{'), NS('N'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(10, TS(LEX_SHORT), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), TS(')'), TS('{'), NS('N'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(9, TS(LEX_SHORT), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), TS(')'), TS('{'), NS('N'), TS('}'), TS(';')),
			Rule::Chain(10, TS(LEX_BOOL), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), TS(')'), TS('{'), NS('N'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(9, TS(LEX_BOOL), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), TS(')'), TS('{'), NS('N'), TS('}'), TS(';')),
			Rule::Chain(10, TS(LEX_STR), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), TS(')'), TS('{'), NS('N'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(9, TS(LEX_STR), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), TS(')'), TS('{'), NS('N'), TS('}'), TS(';')),
			Rule::Chain(10, TS(LEX_CHAR), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), TS(')'), TS('{'), NS('N'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(9, TS(LEX_CHAR), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), TS(')'), TS('{'), NS('N'), TS('}'), TS(';')),
			Rule::Chain(11, TS(LEX_SHORT), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(10, TS(LEX_SHORT), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'), TS(';')),
			Rule::Chain(11, TS(LEX_BOOL), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(10, TS(LEX_BOOL), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'), TS(';')),
			Rule::Chain(11, TS(LEX_STR), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(10, TS(LEX_STR), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'), TS(';')),
			Rule::Chain(11, TS(LEX_CHAR), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'), TS(';'), NS('S')),
			Rule::Chain(10, TS(LEX_CHAR), TS(LEX_FUNCTION), TS(LEX_IDENTIFIER), TS('('), NS('F'), TS(')'), TS('{'), NS('N'), TS('}'), TS(';'))
		),
		Rule(
			NS('N'), GRB_ERROR_SERIES + 1,    // ����������� � ��������
			22,
			Rule::Chain(5, TS(LEX_NEW), NS('T'), TS(LEX_IDENTIFIER), TS(';'), NS('N')),
			Rule::Chain(7, TS(LEX_NEW), NS('T'), TS(LEX_IDENTIFIER), TS('='), NS('E'), TS(';'), NS('N')),
			Rule::Chain(4, TS(LEX_NEW), NS('T'), TS(LEX_IDENTIFIER), TS(';')),
			Rule::Chain(6, TS(LEX_NEW), NS('T'), TS(LEX_IDENTIFIER), TS('='), NS('E'), TS(';')),
			Rule::Chain(4, TS(LEX_IDENTIFIER), TS('='), NS('E'), TS(';')),
			Rule::Chain(5, TS(LEX_IDENTIFIER), TS('='), NS('E'), TS(';'), NS('N')),
			Rule::Chain(4, TS(LEX_WRITE), NS('L'), TS(';'), NS('N')),
			Rule::Chain(3, TS(LEX_WRITE), NS('L'), TS(';')),
			Rule::Chain(4, TS(LEX_WRITELINE), NS('L'), TS(';'), NS('N')),
			Rule::Chain(3, TS(LEX_WRITELINE), NS('L'), TS(';')),
			Rule::Chain(6, TS(LEX_STRDUPLICATE), TS('('), NS('W'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(5, TS(LEX_STRDUPLICATE), TS('('), NS('W'), TS(')'), TS(';')),
			Rule::Chain(6, TS(LEX_STRLENGTH), TS('('), NS('W'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(5, TS(LEX_STRLENGTH), TS('('), NS('W'), TS(')'), TS(';')),
			Rule::Chain(6, TS(LEX_IDENTIFIER), TS('('), NS('W'), TS(')'), TS(';'), NS('N')),
			Rule::Chain(5, TS(LEX_IDENTIFIER), TS('('), NS('W'), TS(')'), TS(';')),
			Rule::Chain(5, TS(LEX_IDENTIFIER), TS('('), TS(')'), TS(';'), NS('N')),
			Rule::Chain(4, TS(LEX_IDENTIFIER), TS('('), TS(')'), TS(';')),
			Rule::Chain(6, TS(LEX_CYCLE), NS('Q'), TS('{'), NS('N'), TS('}'), NS('N')),
			Rule::Chain(5, TS(LEX_CYCLE), NS('Q'), TS('{'), NS('N'), TS('}')),
			Rule::Chain(4, TS(LEX_RETURN), NS('L'), TS(';'), NS('N')),
			Rule::Chain(3, TS(LEX_RETURN), NS('L'), TS(';'))
		),
		Rule(
			NS('E'), GRB_ERROR_SERIES + 2,    // ������ � ���������
			14,
			Rule::Chain(1, TS(LEX_IDENTIFIER)),
			Rule::Chain(1, TS(LEX_LITERAL)),
			Rule::Chain(3, TS('('), NS('E'), TS(')')),
			Rule::Chain(4, TS(LEX_IDENTIFIER), TS('('), NS('W'), TS(')')),
			Rule::Chain(3, TS(LEX_IDENTIFIER), TS('('), TS(')')),
			Rule::Chain(4, TS(LEX_STRDUPLICATE), TS('('), NS('W'), TS(')')),
			Rule::Chain(4, TS('a'), TS('('), NS('W'), TS(')')),
			Rule::Chain(2, TS(LEX_IDENTIFIER), NS('M')),
			Rule::Chain(2, TS(LEX_LITERAL), NS('M')),
			Rule::Chain(4, TS('('), NS('E'), TS(')'), NS('M')),
			Rule::Chain(5, TS(LEX_IDENTIFIER), TS('('), NS('W'), TS(')'), NS('M')),
			Rule::Chain(4, TS(LEX_IDENTIFIER), TS('('), TS(')'), NS('M')),
			Rule::Chain(5, TS(LEX_STRDUPLICATE), TS('('), NS('W'), TS(')'), NS('M')),
			Rule::Chain(5, TS(LEX_STRLENGTH), TS('('), NS('W'), TS(')'), NS('M'))
		),
		Rule(
			NS('F'), GRB_ERROR_SERIES + 3,    // ������ � ���������� �������
			8,
			Rule::Chain(2, TS(LEX_SHORT), TS(LEX_IDENTIFIER)),
			Rule::Chain(2, TS(LEX_STR), TS(LEX_IDENTIFIER)),
			Rule::Chain(2, TS(LEX_CHAR), TS(LEX_IDENTIFIER)),
			Rule::Chain(2, TS(LEX_BOOL), TS(LEX_IDENTIFIER)),
			Rule::Chain(4, TS(LEX_SHORT), TS(LEX_IDENTIFIER), TS(','), NS('F')),
			Rule::Chain(4, TS(LEX_STR), TS(LEX_IDENTIFIER), TS(','), NS('F')),
			Rule::Chain(4, TS(LEX_CHAR), TS(LEX_IDENTIFIER), TS(','), NS('F')),
			Rule::Chain(4, TS(LEX_BOOL), TS(LEX_IDENTIFIER), TS(','), NS('F'))
		),
		Rule(
			NS('W'), GRB_ERROR_SERIES + 4,    // ������ � ���������� ���������� ������� 
			12,
			Rule::Chain(1, TS(LEX_IDENTIFIER)),
			Rule::Chain(1, TS(LEX_LITERAL)),
			Rule::Chain(3, TS(LEX_IDENTIFIER), TS(','), NS('W')),
			Rule::Chain(3, TS(LEX_LITERAL), TS(','), NS('W')),
			Rule::Chain(3, TS(LEX_IDENTIFIER), TS('('), TS(')')),
			Rule::Chain(5, TS(LEX_IDENTIFIER), TS('('), TS(')'), TS(','), NS('W')),
			Rule::Chain(4, TS(LEX_IDENTIFIER), TS('('), NS('W'), TS(')')),
			Rule::Chain(6, TS(LEX_IDENTIFIER), TS('('), NS('W'), TS(')'), TS(','), NS('W')),
			Rule::Chain(4, TS(LEX_STRDUPLICATE), TS('('), NS('W'), TS(')')),
			Rule::Chain(6, TS(LEX_STRDUPLICATE), TS('('), NS('W'), TS(')'), TS(','), NS('W')),
			Rule::Chain(4, TS(LEX_STRLENGTH), TS('('), NS('W'), TS(')')),
			Rule::Chain(6, TS(LEX_STRLENGTH), TS('('), NS('W'), TS(')'), TS(','), NS('W'))
		),
		Rule(
			NS('M'), GRB_ERROR_SERIES + 5,    // ��������
			16,
			Rule::Chain(2, TS('+'), NS('E')),
			Rule::Chain(3, TS('+'), NS('E'), NS('M')),
			Rule::Chain(2, TS('-'), NS('E')),
			Rule::Chain(3, TS('-'), NS('E'), NS('M')),
			Rule::Chain(2, TS('/'), NS('E')),
			Rule::Chain(3, TS('/'), NS('E'), NS('M')),
			Rule::Chain(2, TS('*'), NS('E')),
			Rule::Chain(3, TS('*'), NS('E'), NS('M')),
			Rule::Chain(2, TS('%'), NS('E')),
			Rule::Chain(3, TS('%'), NS('E'), NS('M')),
			Rule::Chain(2, TS(LEX_NOTEQUALS), NS('L')),
			Rule::Chain(2, TS(LEX_INEQUALITY), NS('L')),
			Rule::Chain(2, TS('>'), NS('L')),
			Rule::Chain(2, TS('<'), NS('L')),
			Rule::Chain(2, TS(LEX_MOREEQUAL), NS('L')),
			Rule::Chain(2, TS(LEX_LESSEQUAL), NS('L'))
		),
		Rule(
			NS('Q'), GRB_ERROR_SERIES + 6,		// �������� ���������
			6,									// Q->  (L<L)  |  (L>L)
			Rule::Chain(5, TS('('), NS('L'), TS('<'), NS('L'), TS(')')),
			Rule::Chain(5, TS('('), NS('L'), TS('>'), NS('L'), TS(')')),
			Rule::Chain(5, TS('('), NS('L'), TS(LEX_NOTEQUALS), NS('L'), TS(')')),
			Rule::Chain(5, TS('('), NS('L'), TS(LEX_INEQUALITY), NS('L'), TS(')')),
			Rule::Chain(5, TS('('), NS('L'), TS(LEX_MOREEQUAL), NS('L'), TS(')')),
			Rule::Chain(5, TS('('), NS('L'), TS(LEX_LESSEQUAL), NS('L'), TS(')'))
		),
		Rule(
			NS('L'), GRB_ERROR_SERIES + 6,		// �������� � ��������������
			2,									// L->  (l)  |  (i)
			Rule::Chain(1, TS(LEX_LITERAL)),
			Rule::Chain(1, TS(LEX_IDENTIFIER))
		),
		Rule(
			NS('T'), GRB_ERROR_SERIES + 7,
			4,
			Rule::Chain(1, TS(LEX_SHORT)),
			Rule::Chain(1, TS(LEX_STR)),
			Rule::Chain(1, TS(LEX_BOOL)),
			Rule::Chain(1, TS(LEX_CHAR))
		)
	);
}
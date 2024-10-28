#pragma once
#include "stdafx.h"
#define LT_NOPRIORITY 0xffffffff		// ��� ����������
#define LEXEMA_FIXSIZE 1 //������������� ������ ������
#define LT_MAXSIZE 4096 //max ���-�� ����� � ������� ������
#define LT_TI_NULLIDX -1 // ��� �������� ������� ���������������
#define LEX_T 't'
#define LEX_USINT 'u'
#define LEX_STRING 's'
#define LEX_BOOLEAN 'b'	
#define LEX_SYMBOL 'c'	
#define LEX_LIB_FUNC 'x'
#define LEX_ID 'i'
#define LEX_LITERAL 'l'
#define LEX_DEF 'f'
#define LEX_HEAD 'm'
#define LEX_NEW 'n'
#define LEX_OPERATOR 'v'
#define LEX_LOG_OPERATOR 'z'
#define LEX_RET 'r'
#define LEX_OUT 'o'
#define LEX_DOT '.'
#define LEX_COMMA ','
#define LEX_OPEN '{'
#define LEX_CLOSE '}'
#define LEX_LEFTHESIS '('
#define LEX_RIGHTHESIS ')'
#define LEX_PLUS '+'
#define LEX_MINUS '-'
#define LEX_STAR '*'
#define LEX_DIRSLASH '/'
#define LEX_LEFTSHIFT '0'
#define LEX_RIGHTSHIFT '1'
#define LEX_LESS '<'
#define LEX_GREATER '>'
#define LEX_NEQU '!'
#define LEX_EQU '='
#define LEX_ASSIGN ':'
#define LEX_WHEN 'w'
#define LEX_OTHERWISE 'e'
#define LEX_ENDW ']'
#define LITERAL_NAME 'L'
#define LEFT_SHIFT_OPERATOR "<~"
#define RIGHT_SHIFT_OPERATOR "~>"
#define LEX_SUBST '@'
#define DATE "DATE"
#define TIME "TIME"
#define BOOLEAN_LIT_TRUE "true"
#define LT_EL(value)  lexTable.table[value]

namespace LT
{
	struct Entry //������ ������� ������
	{
		char lexema;		// �������
		int sn;				//����� ������ � �������� ������
		int pn;				// ����� ������� � �������� ����
		int idxTI;			// ������ � ������� ��������������� ��� LT_TI_NULLDIX
		int priority;		// ��������� ��������
		char operation;		// ������ �������� �������� (���� 0x00, ���� �� �������� ���������)
	};
	struct LexTable
	{
		int maxsize;	//������� ������� ������ < LT_MAXSIZE
		int size;		//������� ������ ������� ������ < maxsize
		std::vector<Entry> table;	//������ ����� ������� ������
	};
	LexTable& Create( //������� ������� ������
			 //������� ������� ������ < LT_MAXSIZE
	);
	void Add(	//�������� ������ � ������� ������
		LexTable& lextable, //��������� ������� ������
		Entry entry				//������ ������� ������
	);
	Entry GetEntry( //�������� ������ ������� ������
		LexTable& lextable,		//��������� ������� ������
		int n					//����� ���������� ������
	);

	Entry CreateLex(
		char lex,
		int line,
		int pos,
		int id_in_TI, 
		int prior
	);

	void Delete(LexTable& lextable); //������� ������� ������(���������� ������)

	void WriteTable(Log::LOG log, LexTable& lexTable);
};


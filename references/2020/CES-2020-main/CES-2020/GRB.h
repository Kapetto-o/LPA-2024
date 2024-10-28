#pragma once
#include "stdafx.h"
typedef short GRBALPHABET; // ������� �������� ����������, ��������� > 0, ����������� < 0
#define GRB_ERROR_SERIES 200
namespace GRB
{
#define NS(n) Rule::Chain::N(n)
#define TS(n) Rule::Chain::T(n)
	struct Rule	 // ������� � ���������� �������
	{
		GRBALPHABET nn;		// ����������(����� ������ �������) < 0
		int iderror;		// ������������� ���������������� ���������
		short size;			// ���-�� ������� - ������ ������ �������
		struct Chain		// �������(������ ����� �������)
		{
			short size;			// ����� �������
			GRBALPHABET* nt;	// ������� ���������� � ������������ 
			Chain() { size = 0; nt = 0; };
			Chain(
				short psize,		// ���-�� �������� � �������
				GRBALPHABET s, ...  // �������(�������� � ����������)
			);
			char* getCChain(char* b);	// �������� ������ ������� �������
			static GRBALPHABET T(char t) { return  GRBALPHABET(t); }; // ��������
			static GRBALPHABET N(char n) { return -GRBALPHABET(n); }; // ����������
			static bool isT(GRBALPHABET s) { return s > 0; };	// ��� ��������?
			static bool isN(GRBALPHABET s) { return !isT(s); };	// ��� ����������?
			static char alphabet_to_char(GRBALPHABET s) { return isT(s) ? char(s) : char(-s); };
		}* chains;
		Rule() { nn = 0x00; size = 0; iderror = 0; chains = nullptr; }
		Rule(
			GRBALPHABET pnn,	// ����������
			int iderror,		// �����. ���������������� ��������� (Error)
			short psize,		// ���-�� ������� - ������ ������ �������
			Chain c, ...		// ��������� �������- ������ ������ �������
		);
		char* getCRule(		// �������� ������� � ���� N->������� (��� ����������)
			char* b,		// �����
			short nchain	// ����� ������� (������ ����� � �������
		);
		short getNextChain(  // �������� ��������� �� j ���������� �������, ������� � ����� ��� -1
			GRBALPHABET t,		   // ������ ������ �������
			Rule::Chain& pchain,   // ������������ �������
			short j				   // ����� �������
		);
	};

	struct Greibach	 // ���������� �������
	{
		short size;				// ���-�� ������
		GRBALPHABET startN;		// ��������� ������
		GRBALPHABET stbottomT;  // ��� �����
		Rule* rules;			// ��������� ������ 
		Greibach() {  size = 0; startN = 0; stbottomT = 0; rules = 0; };
		Greibach(
			GRBALPHABET pstartN,	// ��������� ������
			GRBALPHABET pstBottomT, // ��� �����
			short psize,			// ���-�� ������ 
			Rule r, ...				// �������
		);
		short getRule(		// �������� �������, ������������ ����� ������� ��� -1
			GRBALPHABET pnn,	// ����� ������ �������
			Rule& prule			// ������������ ������� ����������
		);
		Rule getRule(short n);  // �������� ������� �� ������
	};
	Greibach getGreibach();   //�������� ����������
};
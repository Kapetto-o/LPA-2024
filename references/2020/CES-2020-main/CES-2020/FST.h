#pragma once
#include "stdafx.h"
#define FST_WORDS_SIZE 24
#define FST_SINGLE_LEX_SIZE 9
#define FST_USINT_BIN_INDEX 0
#define FST_USINT_OCT_INDEX 1
#define FST_USINT_DEC_INDEX 2

namespace FST
{
	// ��� �������������� ��������
	enum USINT_LIT_TYPE { NO_USINT_LIT, BIN_LIT, OCT_LIT, DEC_LIT};	
	enum LEX_TYPE { UNIDENTIFIED = -1, ID, NEED_PRIORITY, DEF_LEX, OPERATION, LOG_OPERATION, STATIC_LIB, LITERAL };
	
	struct RELATION //�����:������ -> ������� ����� ��������� ��
	{
		char symbol; //������ ��������
		short nnode; //����� ������� �������
		RELATION(
			char c = 0x00,  //������ ��������
			short ns = NULL //����� ���������
		);
	};
	struct NODE
	{
		short n_relation;		//���������� ���������� �����
		RELATION* relations;	//����������� ����
		NODE();
		NODE(
			short n,			//���������� ���������� �����
			RELATION rel, ...	//������ ����
		);
	};
	struct STATE_MACHINE
	{
		LEX_TYPE lextype;
		char lexema;
		USINT_LIT_TYPE ult = NO_USINT_LIT;
	};
	struct FST //������������������� �������� �������
	{
		char  lexema;		//������� (������, ����������� 0x00)
		LEX_TYPE lexType;	// ��� �������
		std::string str;	// ������� (������, ����������� 0�00)
		short position;		//������� ������� � �������
		short nstates;		//���������� ��������� ��������
		NODE* nodes;		//���� ���������: [0] - ��������� ���������, [nstate - 1] - ��������
		short* rstates;		//��������� ��������� �������� �� ������ �������
		FST();
		FST(
			char c,					// �������
			LEX_TYPE l_t,			// ��� �������
			std::string s,		//������� (������, ����������� 0x00)
			short ns,		//���������� ��������� ��������
			NODE n, ...		//������ ��������� (���� ���������)
		);
	};
	bool execute(	//��������� ������������� �������
		FST& fst	
	);
	FST* fstSingleLex();	
	FST* fstWords();		
};

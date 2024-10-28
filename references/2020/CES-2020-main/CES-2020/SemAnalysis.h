#pragma once
#include "stdafx.h"
#define FUNC_MAX_SIZE 5	// ������������ ���������� ������� � ���������� � ���
namespace SA
{
	enum ERROR { NO_ERRORS, PARMS_COUNT, PARMS_TYPE };

	// ��������� �������
	struct Function
	{
		int size = 0;
		std::string name;
		IT::IDDATATYPE* arrayOfDataType;	// ������ ����� ����������
		Function();
	};

	// ��������� ������� � ���������
	struct LocalFunctions
	{
		Function* arrayOfFunction;
		int size = 0;
		LocalFunctions();
	};

	// �������� �� ����������� ����� ���������� � ����� ������������� �������� �������
	ERROR CheckParms(LocalFunctions* localFunctions, Function* arr_of_it_entry, std::string name);

	// ������ ������������� ������
	void startSemAnalysis(LT::LexTable& lexTable, IT::IdTable& idTable);

	// ������� ��� �������� �������� ������ ��� ������������
	//(����� ���������� ���� Bool, � � ������������ ��������� 1>2)
	void isCorrectType(LT::LexTable &lexTable, IT::IdTable &idTable);

	// �������, ������� ���������, ������������ �� � ��������� ����������� ����������
	void isIdWasUsed(LT::LexTable& lexTable, IT::IdTable& idTable);

	// �������� �� ��, ��� ������� ����������� ���������� ���������� ��� ����������
	void isStaticFunc(LT::LexTable& lexTable, IT::IdTable& idTable);
}
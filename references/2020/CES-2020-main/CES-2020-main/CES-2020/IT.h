#pragma once
#include "stdafx.h"
#define ID_MAXSIZE 10 //max ���-�� �������� � id
#define TI_MAXSIZE 4096 //max ���-�� ����� � ������� id
#define TI_USINT_DEFAULT 0x00000000 //�������� �� ��������� ��� integer
#define TI_STR_DEFAULT 0x00		//�������� �� ����� ��� string
#define TI_NULLIDX -1 //��� ��-�� ������� id
#define TI_STR_MAXSIZE 255
#define TI_USINT_MAXVALUE 255
#define TI_EL(value) idTable.table[value]

namespace IT // ������� id
{	//���� ������ id
	enum IDDATATYPE { OFF = 0, USINT = 1, STRING = 2, BOOLEAN = 3, SYMBOL = 4};
	//���� id: ����������, �������, ��������, �������, ��������
	enum IDTYPE {D = 0, V = 1, F = 2, P = 3, L = 4, OP = 5};	  


	struct Entry //������ ������� id
	{
		int idxfirstLE;		//������ ������ ������ � ��
		std::string id;		//id (������������� ��������� �� ID_MAXSIZE)
		IDDATATYPE iddatatype; //��� ������
		IDTYPE idtype;			//��� ��������������
		struct
		{
			bool vBoolean;
			char vSymbol;
			int vUsint; //�������� usint
			struct
			{
				int len;	//���-�� �������� � string
				std::string str; //������� string
			}vString; //�������� string
		}value;
	};
	
	struct IdTable //��������� ������� id
	{
		int maxsize; //������� ������� id < TI_MAXSIZE
		int size;	//������� ������ ������� id
		std::vector<Entry> table; //������ ����� ������� id
	};
	IdTable& Create(	//������� ������� id
		 //������� ������� id < TI_MAXSIZE
	);

	void Add(	//�������� ������ � ������� id 
		IdTable& idtable, //��������� ������� id
		Entry entry		//������ ������� ���������������
	);
	Entry GetEntry(	//�������� ������ ������� id
		IdTable& idtable, //��������� ������� id
		int n		//����� ���������� ������
	);

	Entry CreateId(
		int line, 
		std::string id, 
		IDDATATYPE id_data_type,
		IDTYPE id_type
	);

	Entry CreateId(
		int line, 
		std::string id, 
		IDDATATYPE id_data_type, 
		IDTYPE id_type, int vUsint
	);

	Entry CreateId(
		int line, 
		std::string id,
		IDDATATYPE id_data_type, 
		IDTYPE id_type, 
		bool vBool
	);

	Entry CreateId(
		int line,
		std::string id,
		IDDATATYPE id_data_type, 
		IDTYPE id_type,  char vSymbol);

	Entry CreateId(
		int line,
		std::string id, 
		IDDATATYPE id_data_type, 
		IDTYPE id_type, 
		std::string vstr
	);

	int IsId(		//�������: ����� ������(���� ����), TI_NULLIDX(���� ���)
		IdTable& idtable,	//��������� ������� ���������������
		std::string id //�������������
	);
	// ����� �������� � ������� ���������������
	int CheckId(
		IdTable& idtable,
		std::string value
	);

	int CheckId(
		IdTable& idtable,
		bool value
	);

	int CheckId(
		IdTable& idtable,
		 char value
	);
	// �������� �� ������������ ��������������
	int IsDublId(
		IdTable& idtable,
		std::string id
	);		
	int CheckId(
		IdTable& idtable,
		int value
	);
	void WriteTable(
		Log::LOG log,
		IdTable& idtable
	);

}
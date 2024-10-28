#pragma once
#include "stdafx.h"
#define PARM_IN	 L"/in:"					//���� ��� ����� ��������� ����
#define PARM_OUT L"/out:"				//���� ��� ����� ���������� ����
#define PARM_LOG L"/log:"				//���� ��� ����� �������
#define PARM_AN  L"/an:"	
#define PARM_MAX_SIZE 300				//max ����� ������ ���������
#define PARM_OUT_DEFAULT_EXT L".asm"	//���������� ����� ���������� ���� �� ���������
#define PARM_LOG_DEFAULT_EXT L".log"	//���������� ����� ���������  �� ���������
#define PARM_AN_DEFAULT_EXT L".an"	


namespace Parm			//��������� ������� ����������
{
	struct PARM			//������� ���������
	{
		wchar_t in[PARM_MAX_SIZE];		// /in: ��� ����� ��������� ����
		wchar_t out[PARM_MAX_SIZE];		// /out: ��� ����� ���������� ����
		wchar_t log[PARM_MAX_SIZE];		// /in: ��� ����� ���������
		wchar_t an[PARM_MAX_SIZE];		
	};
											//int _tmain(int argc, _TCHAR* argv[])
	PARM getparm(int argc, _TCHAR* argv[]); //������������ struct PARM �� ������ ���������� ������� main
}
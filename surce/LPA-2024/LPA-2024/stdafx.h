// stdafx.h: ��� �������������� ���������������� ������������ ����.
// ������������� ���� ����� ������������� ������ ���� ���, ��� �������� ����������� ������.
// ��� ����� ������ �� ������ IntelliSense, ������� ������ ������� ��������� � ���������� ����.
// ������ ��������� ������ �� ����������� ����� ������ ����� ���������� ������ �������� � ��������� ���������� ����(!) ���� ������.
// �� ���������� ���� �����, ������� ���������� ����� ��������, ��� ��� � ���� ������ �������� � ������������������ �� �����.

#ifndef STDAFX_H
#define STDAFX_H

#define LENGTHOF(x)(sizeof(x)/sizeof(*x))
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <mbstring.h>
#include <iomanip>
#include <string>
#include <stack>

#include "CodeGeneration.h"
#include "Error.h"
#include "FST.h"
#include "Graphs.h"
#include "Greibach.h"
#include "In.h"
#include "IT.h"
#include "LexicalAnalyzer.h"
#include "Log.h"
#include "LT.h"
#include "MFST.h"
#include "Parm.h"
#include "Polish.h"
#include "Semantic.h"
#include "Token.h"


#endif //STDAFX_H
#pragma once

// stdafx.h: ��� �������������� ���������������� ������������ ����.
// ������������� ���� ����� ������������� ������ ���� ���, ��� �������� ����������� ������.
// ��� ����� ������ �� ������ IntelliSense, ������� ������ ������� ��������� � ���������� ����.
// ������ ��������� ������ �� ����������� ����� ������ ����� ���������� ������ �������� � ��������� ���������� ����(!) ���� ������.
// �� ���������� ���� �����, ������� ���������� ����� ��������, ��� ��� � ���� ������ �������� � ������������������ �� �����.


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

#include "Log.h"
#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Token.h"
#include "LexicalAnalyzer.h"
#include "LT.h"
#include "IT.h"
#include "FST.h"
#include "Graphs.h"
#include "Polish.h"
#pragma once

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

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <stack>

#include "FST.h"
#include "In.h"
#include "Token.h"
#include "Error.h"
#include "LexicalAnalyzer.h"
#include "Graphs.h"
#include "IT.h"
#include "LT.h"



#include <SDKDDKVer.h>
#include <stdio.h>
#include <tchar.h>
#include <ctime>
#include <mbstring.h>
#include <iomanip>

#endif // STDAFX_H

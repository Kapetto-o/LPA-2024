#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

#include "FST.h"
#include "In.h"
#include "Token.h"
#include "Error.h"


// pch.h: ��� �������������� ���������������� ������������ ����.
// ������������� ���� ����� ������������� ������ ���� ���, ��� �������� ����������� ������.
// ��� ����� ������ �� ������ IntelliSense, ������� ������ ������� ��������� � ���������� ����.
// ������ ��������� ������ �� ����������� ����� ������ ����� ���������� ������ �������� � ��������� ���������� ����(!) ���� ������.
// �� ���������� ���� �����, ������� ���������� ����� ��������, ��� ��� � ���� ������ �������� � ������������������ �� �����.

#ifndef PCH_H
#define PCH_H

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


#include "In.h"
#include "LT.h"
#include "IT.h"
#include "FST.h"
#include "Graphs.h"

#endif //PCH_H

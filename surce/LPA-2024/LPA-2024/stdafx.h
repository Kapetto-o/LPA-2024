// stdafx.h: это предварительно скомпилированный заголовочный файл.
// Перечисленные ниже файлы компилируются только один раз, что ускоряет последующие сборки.
// Это также влияет на работу IntelliSense, включая многие функции просмотра и завершения кода.
// Однако изменение любого из приведенных здесь файлов между операциями сборки приведет к повторной компиляции всех(!) этих файлов.
// Не добавляйте сюда файлы, которые планируете часто изменять, так как в этом случае выигрыша в производительности не будет.

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

#include "Error.h"
#include "FST.h"
#include "Graphs.h"
#include "IT.h"
#include "LexicalAnalyzer.h"
#include "Log.h"
#include "LT.h"
#include "Parm.h"
#include "Token.h"


#endif //STDAFX_H
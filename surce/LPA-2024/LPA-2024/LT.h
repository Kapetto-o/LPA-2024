#pragma once
#include "stdafx.h"

#define LEXEMA_FIXSIZE 1               
#define LT_MAXSIZE 4096                 
#define LT_TI_NULLTDX 0xffffffff        

// Типы данных

#define LEX_SHORT				'd'
#define LEX_CHAR				'c'
#define LEX_STR					's'
#define LEX_BOOL				'b'

// Идентификаторы и литералы
#define LEX_IDENTIFIER			'i'
#define LEX_LITERAL				'l'

// Функции

#define LEX_STRDUPLICATE		'g'
#define LEX_STRLENGTH			'h'
#define LEX_STRTRANSINT			't'
#define LEX_MAIN				'm'

// Ключевые слова
#define LEX_NEW					'n'

#define LEX_FUNCTION			'f'
#define LEX_RETURN				'r'

// Операторы вывода в консоль и цикла

#define LEX_WRITELINE			'w'
#define LEX_WRITE				'v'
#define LEX_CYCLE				'p'

// Скобки

#define LEX_LEFTBRACE_OPEN		'{'
#define LEX_RIGHTBRACE_CLOSE	'}'
#define LEX_LEFTHESIS_OPEN		'('
#define LEX_RIGHTHESIS_CLOSE	')'

// Арифметические операторы

#define LEX_ADDITION			'+'
#define LEX_SUBSTRACTION		'-'
#define LEX_MULTIPLICATION		'*'
#define LEX_DIVISION			'/'
#define LEX_REMAINDERDIVISION	'%'
#define LEX_EQUALS				'='

// Логические операторы

#define LEX_MORE				'>'
#define LEX_LESS				'<'
#define LEX_MOREEQUAL			']'
#define LEX_LESSEQUAL			'['
#define LEX_INEQUALITY			'#'
#define LEX_NOTEQUALS			'!'

// Разное

#define LEX_COMMA				','
#define LEX_SEMICOLON			';'

namespace LT
{
	struct Entry
	{
		char lexema;		// символ лексемы
		int sn;				// номер строки в коде
		int idxTI;			// номер в IT
	};

	struct LexTable
	{
		int maxsize;
		int size;
		Entry* table;
	};

	LexTable Create(int size);
	void Add(LexTable& lextable, Entry entry);
	void Delete(LexTable& lextable);
	void SaveToFile(LexTable& lextable, wchar_t outfile[]);

	Entry GetEntry(LexTable& lextable, int n);

	Entry CreateEntry(char lexema, int line);
	Entry CreateEntry(char lexema, int line, int idTI);
	void SaveLexTableInFile(LexTable lextable, wchar_t outfile[]);
};
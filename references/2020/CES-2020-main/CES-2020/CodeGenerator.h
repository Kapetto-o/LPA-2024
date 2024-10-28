#pragma once
#include "stdafx.h"

namespace CodeGen
{
	void Head(Lex::LEX &lex, Log::LOG &log);
	void Const(Lex::LEX &lex, Log::LOG &log);
	void Data(Lex::LEX &lex, Log::LOG &log);
	void Code(Lex::LEX &lex, Log::LOG &log);
	void Generation(Lex::LEX &lex, Log::LOG log);
	// ������� ��� ���������� ��������� ��� ��������������� � ��������� ������� asm
	void ChangeNames(Lex::LEX &lex);
}

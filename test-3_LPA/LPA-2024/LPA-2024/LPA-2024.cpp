﻿#include "stdafx.h"
#include <cwchar>
#define NOMINMAX
#include <Windows.h>

int _tmain(int argc, _TCHAR** argv)
{
	//argc = 3;
	//argv[1] = (_TCHAR*)L"-in:D:\\KPO_3sem\\SIV-2023\\SIV-2023\\ControlExample.txt";
	//argv[1] = (_TCHAR*)L"-in:D:\\KPO_3sem\\SIV-2023\\SIV-2023\\SemErrors.txt";
	//argv[2] = (_TCHAR*)L"-out:D:\\KPO_3sem\\SIV-2023\\SIV-2023\\SIV_result.asm";
	//argv[3] = (_TCHAR*)L"-log:D:\\KPO_3sem\\SIV-2023\\SIV-2023\\Logger.txt";
	//argv[4] = (_TCHAR*)L"-an:D:\\KPO_3sem\\SIV-2023\\SIV-2023\\Analize.txt";

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		std::ofstream clearFile(parm.an, std::ios_base::trunc);
		log = Log::getlog(parm.log);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);

		In::IN in = In::GetIn(parm.in, parm.out);
		Log::WriteIn(log, in);
		Log::WriteLine(log, "No forbidden characters\n", "");

		Log::WriteLine(log, "Tokenization : ", "");
		Tokens::TokenTable tokentable = Tokens::Tokenize(in);
		Log::WriteLine(log, " Completed successfully\n", "");

		Log::WriteLine(log, "Lexical analysis : ", "");
		LA::LEX lex = LA::FillingInTables(tokentable);
		Log::WriteLine(log, " Completed successfully\n", "");

		LT::SaveToFile(lex.lextable, parm.an);
		IT::SaveToFile(lex.idtable, parm.an);

		Log::Close(log);
		std::cout << "Code translation completed successfully\n";
	}
	catch (Error::ERROR e)
	{
		std::cout << "Произошла ошибка\n";
		Log::WriteLine(log, "- ERROR\n", "");
		Log::WriteError(log, e);
	}
	return 0;
}
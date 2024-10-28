#include "stdafx.h"

ofstream fout("Code.js");

void Generation(LT::LexTable& Lextable, IT::IdTable& IDtable, In::Words* words)
{
	fout << "function avr(a,b,c)" << endl << "{" << endl
		<< "var sum = 0;" << endl << "var res = 1;" << endl
		<< "sum=a+b+c;" << endl
		<< endl
		<< "res=sum/3;" << endl
		<< "document.write(res);" << endl
		<< "}" <<endl;
	for (int i = 0; i < Lextable.size; i++)
	{
		switch (Lextable.table[i].lexema)
		{
		case LEX_MREQ:
		{
			fout << ">=";
			break;
		}
		case LEX_LSEQ:
		{
			fout << "<=";
			break;
		}
		case LEX_NOT:
		{
			fout << Lextable.table[i].lexema << "=";
			break;
		}
		case LEX_EQ:
		{
			fout << "==";
			break;
		}
		case LEX_PLUS:
		case LEX_STAR:
		case LEX_MINUS:
		case LEX_DIRSLASH:
		case LEX_EQUAL:
		case LEX_MORE:
		case LEX_LESS:
		{
			fout << " " << Lextable.table[i].lexema << " ";
			break;
		}
		case LEX_COMMA:
		case SPACE:
		{
			fout << Lextable.table[i].lexema << " ";
			break;
		}

		case LEX_RIGHTTHESIS:
		case LEX_LEFTTHESIS:
		{
			fout << Lextable.table[i].lexema;
			break;
		}
		case LEX_LEFTBRACE:
		{

			fout << endl << Lextable.table[i].lexema << endl;
			break;
		}
		case LEX_BRACELET:
		{

			fout << Lextable.table[i].lexema << endl << endl;
			break;
		}
		case LEX_SEPARATOR:
		{
			fout << Lextable.table[i].lexema << endl;
			break;
		}
		case  LEX_INIT:
		{
			fout << "var ";
			break;
		}

		case LEX_LITERAL:
		{
			if (IDtable.table[Lextable.table[i].idxTI].iddatatype == IT::NUM)
				fout << IDtable.table[Lextable.table[i].idxTI].value.vNUM;
			else fout << IDtable.table[Lextable.table[i].idxTI].value.vSTR.str;
			break;
		}
		case LEX_ID:
		{
			fout << IDtable.table[Lextable.table[i].idxTI].id;
			break;
		}
		case LEX_OUT:
		{
			fout << "document.write('<br>');" << endl;
			fout << "document.write";
			break;
		}
		case LEX_FUNCTION:
		{
			fout << "function ";
			break;
		}
		case LEX_RETURN:
		{
			fout << words[i].word << " ";
			break;
		}
		case LEX_LIB:
		{
			fout << "document.write('Now you can use Math functions')";
			break;
		}
		case LEX_AVR:
		{
			fout << "avr";
			for (++i; Lextable.table[i].lexema != LEX_RIGHTTHESIS; i++)
				fout << words[i].word;
			fout << words[i].word;
			break;
		}
		case LEX_POW:
		{
			fout << "Math.pow";
			for (++i; Lextable.table[i].lexema != LEX_RIGHTTHESIS; i++)
				fout << words[i].word;
			fout << words[i].word;
			break;
		}
		case LEX_UNTIL:
		{
			fout << "while";
			break;
		}
		}
	}
	fout.close();
}

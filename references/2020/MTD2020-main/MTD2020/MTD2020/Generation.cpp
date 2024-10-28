#include "stdafx.h"
#include "Generation.h"

namespace Gen
{
	ofstream fout("IntoJSGeneration.html");
	void Head()
	{
		fout << "<!doctype html>" << endl;
		fout << "<html>" << endl;
		fout << "	<head>" << endl;

		fout << "		<title>LRD-2019</title>" << endl;
		fout << "		<script type=\"text/javascript\" src=\"in.txt.js\">" << endl;
		fout << "		</script>" << endl;
		fout << "	</head>" << endl;
		fout << "	<body>" << endl;
		fout << "	</body>" << endl;
		fout << "</html>" << endl;
		fout.close();
	}

	Js getjs(wchar_t jsfile[])
	{
		Js js;
		wcscpy_s(js.jsfile, jsfile);
		ofstream* FILE = new ofstream;
		(*FILE).open(jsfile);
		if (!(*FILE).is_open())
			throw ERROR_THROW(108, ERROR_ZERO_LINE, ERROR_ZERO_COL);
		js.stream = FILE;
		return js;
	}
	void StartGeneration(LEX::LexTable& ltable, ID::IdTable& itable, Gen::Js& js)
	{
		Head();
		bool flag = false;
		for (unsigned int i = 0; i < (unsigned int)ltable.size; i++)
		{
			if (ltable.table[i].lexema == LEX_UWHOLE)
			{
				if (ltable.table[i + 1].lexema == LEX_FUNCTION)
				{
					*js.stream << "function ";
				}
				else if (ltable.table[i - 1].lexema != LEX_LEFTHESIS && ltable.table[i - 1].lexema != LEX_COMMA)
				{				
					*js.stream << "var ";
				}
			}
			if (ltable.table[i].lexema == LEX_LITERAL)
			{

				if (ltable.table[i].system == 10)
				{
					*js.stream << ltable.table[i].buf;

				}
				else if (ltable.table[i].system == 8)
				{
					std::string oct = ltable.table[i].buf;
					oct.erase(0, 2);
					*js.stream << "0o" << oct;
				}
				else {
					*js.stream << ltable.table[i].buf;
				}
			}
			if (ltable.table[i].lexema == LEX_LIBFUNC)
			{
				if (ltable.table[i].parm == 1)
				{
					*js.stream << ltable.table[i + 2].buf << ".slice(0)";
					i = i + 4;
				}
				if (ltable.table[i].parm == 2)
				{
					*js.stream << ltable.table[i + 2].buf << " + " << ltable.table[i + 4].buf;
					i = i + 6;
				}
			}
			if (ltable.table[i].lexema == LEX_ID)
			{
				if (strcmp(ltable.table[i].buf, "var") == 0 || strcmp(ltable.table[i].buf, "let") == 0 || strcmp(ltable.table[i].buf, "const") == 0
					|| strcmp(ltable.table[i].buf, "void") == 0 || strcmp(ltable.table[i].buf, "new") == 0 || strcmp(ltable.table[i].buf, "try") == 0
					|| strcmp(ltable.table[i].buf, "for") == 0)
				{
					throw ERROR_THROW(800, ltable.table[i].sn, ERROR_ZERO_COL);
				}
				else {
					if (ltable.table[i + 1].lexema == LEX_LEFTHESIS || ltable.table[i + 1].lexema == LEX_RIGHTHESIS || ltable.table[i + 1].lexema == LEX_COMMA)
					{
						*js.stream << ltable.table[i].buf;
					}
					else
					{
						*js.stream << ltable.table[i].buf << " ";
					}
				}

			}
			if (ltable.table[i].lexema == LEX_LEFTHESIS)
			{
				*js.stream << "(";
			}
			if (ltable.table[i].lexema == LEX_RIGHTHESIS)
			{
				*js.stream << ")";
			}
			if (ltable.table[i].lexema == LEX_LEFTBRACE)
			{
				*js.stream << "{";
			}
			if (ltable.table[i].lexema == LEX_RIGHTBRACE)
			{

				*js.stream << "}";

			}
			if (ltable.table[i].lexema == LEX_REPAY)
			{
				*js.stream << "return ";
			}
			if (ltable.table[i].lexema == LEX_MEOUT)
			{
				*js.stream << "document.write('<br>');" << endl;
				*js.stream << "document.write";

			}
			if (ltable.table[i].lexema == LEX_PROGRAM)
			{
				*js.stream << endl;
			}

			if (ltable.table[i].lexema == LEX_IF)
			{
				*js.stream << "if ";
			}
			if (ltable.table[i].lexema == LEX_ELSE)
			{
				*js.stream << "else";
			}

			if (ltable.table[i].lexema == LEX_POINT)
			{
				*js.stream << ";" << endl;

				
				int j = i;

				while (ltable.table[j - 1].lexema != LEX_POINT &&
					ltable.table[j - 1].lexema != LEX_LEFTBRACE) {
					if (ltable.table[j - 1].lexema == LEX_COMPARE) {
						int k = 0;
						while (k != itable.size) {
							if (strcmp(ltable.table[j - 2].buf, itable.table[k].id) == 0)
							{
								if (itable.table[k].iddatatype == ID::INT) {
									ALERT_BECAUSE_OF_MINUS;
									j--;
									continue;
								}
								break;
							}
							k++;
						}
					}
					j--;
				}

				j = i;
				while (ltable.table[j - 1].lexema != LEX_POINT &&
					ltable.table[j - 1].lexema != LEX_LEFTBRACE) {
					if (ltable.table[j - 1].lexema == LEX_COMPARE) {
						int k = 0;
						while (k != itable.size) {
							if (strcmp(ltable.table[j - 2].buf, itable.table[k].id) == 0)
							{
								if (itable.table[k].iddatatype == ID::INT) {
									ALERT_BECAUSE_OF_NOT_INT;
									j--;
									continue;
								}
								break;
							}
							k++;
						}
					}
					j--;
				}
				continue;
			}
			if (ltable.table[i].lexema == LEX_COMMA)
			{
				*js.stream << ",";
			}
			if (ltable.table[i].lexema == LEX_PLUS)
			{
				*js.stream << " + ";
			}
			if (ltable.table[i].lexema == LEX_MINUS)
			{
				*js.stream << " - ";
			}
			if (ltable.table[i].lexema == LEX_STAR)
			{
				*js.stream << " * ";
			}
			if (ltable.table[i].lexema == LEX_DIRSLASH)
			{
				*js.stream << " / ";
			}
			if (ltable.table[i].lexema == LEX_AND)
			{
				*js.stream << " & ";
			}
			if (ltable.table[i].lexema == LEX_OR)
			{
				*js.stream << " | ";
			}
			if (ltable.table[i].lexema == LEX_NOT)
			{
				*js.stream << " ~ ";
			}
			if (ltable.table[i].lexema == LEX_COMPARE)
			{
				*js.stream << " = ";
			}
			if (ltable.table[i].lexema == LEX_EQUALLY)
			{
				*js.stream << " == ";
			}
			if (ltable.table[i].lexema == LEX_MORE)
			{
				*js.stream << " > ";
			}
			if (ltable.table[i].lexema == LEX_LESS)
			{
				*js.stream << " < ";
			}
			if (ltable.table[i].sn != ltable.table[i + 1].sn)
			{
				*js.stream << endl;
			}

		}
	}
}
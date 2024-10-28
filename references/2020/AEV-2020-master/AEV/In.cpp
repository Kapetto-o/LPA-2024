#include "stdafx.h"


namespace In
{
	IN getin(std::ofstream* stream, wchar_t Infile[])
	{
		std::ifstream txtfile(Infile);
		if (!txtfile.is_open())
			throw ERROR_THROW(50);
		IN InS;
		InS.text = new unsigned char[IN_MAX_LEN_TEXT];
		int pos = 0;
		unsigned char rSymb = IN_CODE_NULL;

		while ((rSymb = txtfile.get()) && (!txtfile.eof()))
		{

			switch (InS.code[rSymb])
			{
			case IN::N:
			{
				InS.text[InS.size++] = rSymb;
				InS.lines++;
				pos = 0;
				break;
			}
			case IN::P:
			{
				pos++;
				if (InS.text[InS.size - 1] == IN::P)
					InS.ignor++;  //����� ������ �������� � ����
				else
					InS.text[InS.size++] = rSymb;
				break;
			}
			case IN::S:
			{
				pos++;
				if (InS.text[InS.size - 1] == IN_CODE_SPACE) //���� � ������ ����� ����������� ��� ������, ������ ��� �� ����� �������
					InS.text[InS.size - 1] = rSymb;
				else
					InS.text[InS.size++] = rSymb;
				break;
			}
			case IN::F:
			{
				Log::writeError(stream, ::Error::GetError(51, InS.lines, InS.size));
				break;
			}
			case IN::I:
			{
				pos++;
				InS.ignor++;
				break;
			}
			case IN::T:
			{
				pos++;
				if (InS.code[InS.text[InS.size - 2]] == IN::S && InS.code[InS.text[InS.size - 1]] == IN::P) //���� �� ������� ��� ������ ����� ����������, ������ ������ �� ����� �������
					InS.text[InS.size - 1] = rSymb;
				else
					InS.text[InS.size++] = rSymb;
				break;
			}
			case IN::K:
			{
				if (InS.text[InS.size - 1] == IN_CODE_SPACE) //���� � ������ ����� ����������� ��� ������, ������ ��� �� ����� �������
					InS.text[InS.size - 1] = rSymb;
				else
					InS.text[InS.size++] = rSymb;
				rSymb = txtfile.get();
				int numOfsym = 0;
				while (InS.code[rSymb] != IN::K)
				{
					numOfsym++; pos++;
					if (InS.code[rSymb] == IN::N) //��� ������� �������� ��������� ������� �� ����� ������ ��� ���������� ����������� �������
					{
						throw ERROR_THROW_IN(53, InS.lines, pos); //������������� ������ ���������
					}
					if (InS.code[rSymb] == IN::F)
					{
						Log::writeError(stream, Error::GetError(51, InS.lines, pos));
					}
					if (numOfsym == 2) //����� ����������� �������� ������ ���������
					{
						throw ERROR_THROW_IN(94, InS.lines, pos);
						break;
					}
					InS.text[InS.size++] = rSymb;
					rSymb = txtfile.get();
				}
				InS.text[InS.size++] = rSymb;
				break;
			}
			}
		}


		InS.text[InS.size] = IN_CODE_NULL;
		return InS;
	}

	int Words::amount = 0;

	void newWord(Words* words, char*& buf, int& posbuf, int line)
	{
		buf[posbuf++] = IN_CODE_NULL; //������� ����� 0 ��������
		strcpy_s((words[Words::amount].word), posbuf, buf); //����������� ����� � ������ ����
		words[Words::amount].line = line; //��������� ������ � �������� ����
		Words::amount++; //��������� ���������� ����
		buf[0] = IN_CODE_NULL;
		posbuf = 0;
	}

	Words* split(Words* words, unsigned char* text, int* code)
	{
		words = new Words[IN_MAX_LEN_TEXT];
		char* buf = new char[IN_MAX_STRING_CODE];
		int posBuf = 0;
		int line = 0;

		for (int i = NULL; text[i] != IN_CODE_NULL; i++)
		{
			switch (code[text[i]])
			{
			case IN::N:
				line++;
			case IN::P:
			{
				if (buf[0] != IN_CODE_NULL)
					newWord(words, buf, posBuf, line);
				break;
			}
			case IN::S:
			{
				if (buf[0] != IN_CODE_NULL)
					newWord(words, buf, posBuf, line); //�������� ����� ����� �����������

				buf[posBuf++] = text[i];
				newWord(words, buf, posBuf, line); //�������� ��� ���������
				break;
			}
			case IN::T:
			{
				buf[posBuf++] = text[i];
				break;
			}
			case IN::K:
			{
				if (buf[0] != IN_CODE_NULL)
					newWord(words, buf, posBuf, line);
				buf[posBuf++] = text[i]; //������ �������
				while (code[text[++i]] != IN::K)
					buf[posBuf++] = text[i];
				buf[posBuf++] = text[i]; //������ �������
				newWord(words, buf, posBuf, line);
				break;
			}
			}
		}
		return words;
	}
}

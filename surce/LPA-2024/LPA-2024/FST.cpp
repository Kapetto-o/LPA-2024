#include "stdafx.h"

namespace FST
{
	RELATION::RELATION(char c, short nn)
	{
		symbol = c;
		nnode = nn;
	};

	NODE::NODE()
	{
		n_relation = 0;
		relations = nullptr;
	};

	NODE::NODE(short n, RELATION rel, ...)
	{
		n_relation = n;
		RELATION* p = &rel;
		relations = new RELATION[n];
		for (short i = 0; i < n; i++) relations[i] = p[i];
	};

	FST::FST(char* s, short ns, NODE n, ...)
	{
		string = s;
		nstates = ns;
		nodes = new NODE[ns];
		NODE* p = &n;
		for (int k = 0; k < ns; k++)
			nodes[k] = p[k];
		rstates = new short[nstates];
		memset(rstates, 0xff, sizeof(short) * nstates);
		rstates[0] = 0;
		position = -1;
	};

	FST::FST(short ns, NODE n, ...)
	{
		nstates = ns;
		nodes = new NODE[ns];
		NODE* p = &n;
		for (int k = 0; k < ns; k++)
			nodes[k] = p[k];
		rstates = new short[nstates];
		memset(rstates, 0xff, sizeof(short) * nstates);
		rstates[0] = 0;
		position = -1;

	}

	FST::FST(char* s, FST& fst)
	{
		this->nodes = new NODE[fst.nstates];
		NODE* temp = fst.nodes;
		short i = 0;
		this->string = s;
		this->nstates = fst.nstates;
		this->rstates = new short[this->nstates];
		while (i < nstates)
		{
			this->nodes[i] = *(temp + i);
			i++;
		};
		rstates[0] = 0;
		position = -1;
	}

	// Выполнение шага из одного массива в другой
	bool step(FST& fst, short*& rstates)
	{
		bool rc = false;
		std::swap(rstates, fst.rstates);

		for (short i = 0; i < fst.nstates; i++)
		{
			if (rstates[i] == fst.position)
			{
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
				{
					// Совпадение простого символа
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					}
					// Совпадение литерала 'a'
					else if (fst.string[fst.position] == '\'' && fst.string[fst.position + 2] == '\'')
					{
						if (fst.nodes[i].relations[j].symbol == fst.string[fst.position + 1]) // Символ внутри кавычек
						{
							fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 3; // Пропуск 3 символов
							rc = true;
						}
					}
					// Совпадение экранированного символа '\n', '\t', '\''
					else if (fst.string[fst.position] == '\'' && fst.string[fst.position + 1] == '\\')
					{
						char escaped_char;
						switch (fst.string[fst.position + 2]) // Определение экранированного символа
						{
						case 'n': escaped_char = '\n'; break;
						case 't': escaped_char = '\t'; break;
						case '\'': escaped_char = '\''; break;
						default: escaped_char = fst.string[fst.position + 2]; break; // Поддержка других символов
						}

						if (fst.nodes[i].relations[j].symbol == escaped_char)
						{
							fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 4; // Пропуск 4 символов
							rc = true;
						}
					}
				}
			}
		}

		return rc;
	}


	// Выполнение распознавания цепочки с помощью алгоритма двух массивов
	bool execute(FST& fst)
	{
		short* rstates = new short[fst.nstates];
		memset(rstates, 0xff, sizeof(short) * fst.nstates);
		short lstring = strlen(fst.string);
		bool rc = true;
		for (short i = 0; i < lstring && rc; i++)
		{
			fst.position++;
			rc = step(fst, rstates);
		}
		delete[] rstates;
		return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
	};
}
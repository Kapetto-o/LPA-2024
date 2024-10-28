#include "stdafx.h"

using namespace std;
int FST_TRACE_n = -1;
char rbuf[205], sbuf[205], lbuf[1024];
namespace MFST
{
	Rl getrul(wchar_t rulefile[])
	{
		Rl rl;
		wcscpy_s(rl.rulefile, rulefile);
		ofstream* FILE = new ofstream;
		(*FILE).open(rulefile);
		if (!(*FILE).is_open())
			throw ERROR_THROW(107, ERROR_ZERO_LINE, ERROR_ZERO_COL);
		rl.stream = FILE;
		return rl;
	}
	void WriteData(Rl rl)
	{
		char Date[50];
		struct tm* date;
		const time_t nowtime = time(NULL);
		date = localtime(&nowtime);
		strftime(Date, 50, "%d.%m.%Y %H:%M:%S, %A", date);
		*rl.stream << "----Протокол rl----" << endl;
		*rl.stream << "Время создания протокола: " << Date << endl;
	}
	MfstState::MfstState()		// конструктор по умолчанию
	{
		lenta_position = 0;		//позиция на ленте
		nrule = -1;				//номер текущего правила
		nrulechain = -1;		//номер текущей цепочки
	}
	MfstState::MfstState(short pposition, MFSTSTSTACK pst, short pnrulechain)  //конструктор (позиция на ленте, стек автомата, номер текущей цепочки и текущего правила)
	{
		lenta_position = pposition;		//позиция на ленте
		st = pst;						//стек автомата
		nrulechain = pnrulechain;		//номер текущего правила и цепочки
	}
	MfstState::MfstState(short pposition, MFSTSTSTACK pst, short pnrule, short pnrulechain)
	{
		lenta_position = pposition;	//позиция в ленте	
		st = pst;					//стек автомата
		nrule = pnrule;				//номер текущего правила
		nrulechain = pnrulechain;	//номер текущей цепочки
	}
	Mfst::MfstDiagnosis::MfstDiagnosis()	//  для  строк диагностики
	{
		lenta_position = -1;
		rc_step = SURPRISE;
		nrule = -1;
		nrule_chain = -1;
	}
	Mfst::MfstDiagnosis::MfstDiagnosis(short plenta_position, RC_STEP prc_step, short pnrule, short pnrule_chain) // диагностика
	{											//(позиция на ленте, код завершения шага, номер правила, номер цепочки правила)
		lenta_position = plenta_position;		//позиция на ленте
		rc_step = prc_step;						//код завершения шага
		nrule = pnrule;							//номер правила
		nrule_chain = pnrule_chain;				//номер цепочки правила
	}
	Mfst::Mfst()			 //конструктор по умолчанию 
	{
		lenta = 0;
		lenta_size = lenta_position = 0;
	}
	Mfst::Mfst(LEX::LexTable plex, GRB::Greibach pgrebach, MFST::Rl rl) //(результат работы лексического анализатора, грамматика Грейбах)
	{
		this->rl = rl;
		grebach = pgrebach;		//Грейбах
		lexTable = plex;		//рез работы лекс анализатора
		lenta = new short[lenta_size = lexTable.size];	//размер ленты = текущий размер таблицы лексем
		for (int i = 0; i < lenta_size; i++)
			lenta[i] = TS(lexTable.table[i].lexema);	//заносит в ленту терминалы
		lenta_position = 0;
		st.push_back(grebach.stbottomT);	//добавляет дно стека
		st.push_back(grebach.startN);	//добавляет стартовый символ
		nrulechain = -1;			//изначально правило равно -1
	}
	Mfst::RC_STEP Mfst::step()		//выполнить шаг автомата
	{
		RC_STEP rc = SURPRISE;		//код возврата = ошибка возврата
		if (lenta_position < lenta_size)
		{
			if (ISNS(st.back()))		//извлекаем последний элемент стека и проверяем нетерминал ли он
			{
				GRB::Rule rule;
				if ((nrule = GRB::getGreibach().getRule(st.back(), rule)) >= 0)//смотрим, если такое правило есть идём дальше, если нет то else
				{
					GRB::Rule::Chain chain;
					if ((nrulechain = rule.getNextChain(lenta[lenta_position], chain, nrulechain + 1)) >= 0)//получаем следующую цепочку и выводим её номер, илбо возвращаем -1
					{
						MFST_TRACE1(rl);	//вывод
						savestate();		//сохранить состояние автомата
						st.pop_back();			//извлекаем верхушку стека.
						push_chain(chain);	//поместить цепочку правила в стек
						rc = NS_OK;			//найдено правило и цепочка... цепочка записана в стек
						MFST_TRACE2(rl);	//вывод
					}
					else
					{
						MFST_TRACE4("TNS_NORULECHAIN/NS_NORULE", rl)//вывод
							savediagnosis(NS_NORULECHAIN);			 //код завершения
						rc = reststate() ? NS_NORULECHAIN : NS_NORULE;	//восстановить состояние автомата
					}
				}
				else
					rc = NS_ERROR; //неизвестный нетерминальный символ грамматики
			}
			else if ((st.back() == lenta[lenta_position]))	//если текущий символ ленты равен вершине стека
			{
				lenta_position++;		//продвигаем ленту
				st.pop_back();				//вершина стека
				nrulechain = -1;		//номер текущего правила равен -1
				rc = TS_OK;
				MFST_TRACE3(rl);
			}
			else
			{
				MFST_TRACE4("TS_NOK/NS_NORULECHAIN", rl)
					rc = reststate() ? TS_NOK : NS_NORULECHAIN;
			}
		}
		else
		{
			rc = LENTA_END;
			MFST_TRACE4("LENTA_END", rl)
		}
		return rc;
	}

	bool Mfst::push_chain(GRB::Rule::Chain chain)	//поместить цепочку правила в стек (цепочка правила)
	{
		for (int i = chain.size - 1; i >= 0; i--)
			st.push_back(chain.nt[i]);
		return true;
	}
	bool Mfst::savestate()	//сохранить состояние автомата
	{
		storestate.push_back(MfstState(lenta_position, st, nrule, nrulechain));
		MFST_TRACE6("SAVESTATE:", storestate.size(), rl);
		return true;
	}
	bool Mfst::reststate()	//восстановить состояние автомата
	{
		bool rc = false;
		MfstState state;
		if (rc = (storestate.size() > 0))
		{
			state = storestate.back();
			lenta_position = state.lenta_position;
			st = state.st;
			nrule = state.nrule;
			nrulechain = state.nrulechain;
			storestate.pop_back();
			MFST_TRACE5("RESSTATE", rl)
				MFST_TRACE2(rl);
		}
		return rc;
	}
	bool Mfst::savediagnosis(RC_STEP prc_step)
	{
		bool rc = false;
		short k = 0;
		while (k < MFST_DIAGN_NUMBER && lenta_position <= diagnosis[k].lenta_position)
			k++;
		if (rc = (k < MFST_DIAGN_NUMBER))
		{
			diagnosis[k] = MfstDiagnosis(lenta_position, prc_step, nrule, nrulechain);
			for (short j = k + 1; j < MFST_DIAGN_NUMBER; j++)
				diagnosis[j].lenta_position = -1;
		}
		return rc;
	}
	bool Mfst::start()
	{
		bool rc = false;
		RC_STEP rc_step = SURPRISE;
		char buf[MFST_DIAGN_MAXSIZE];
		rc_step = step();
		while (rc_step == NS_OK || rc_step == NS_NORULECHAIN || rc_step == TS_OK || rc_step == TS_NOK)
			rc_step = step();
		switch (rc_step)
		{
		case NS_NORULE:
			MFST_TRACE4("-------> NS_NORULE", rl);
			*rl.stream << "--------------------------------------------------------------" << endl;
			*rl.stream << getDiagnosis(0, buf) << endl;
			*rl.stream << getDiagnosis(1, buf) << endl;
			*rl.stream << getDiagnosis(2, buf) << endl;
			break;
		case NS_NORULECHAIN:
			MFST_TRACE4("------> NS_NORULECHAIN", rl)
				break;
		case NS_ERROR:
			MFST_TRACE4("------> NS_ERROR", rl)
				break;
		case LENTA_END:
			MFST_TRACE4("-------> NS_LENTA_END", rl)
				* rl.stream << "--------------------------------------------------------------" << endl;
			*rl.stream << setw(4) << left << "Всего строк " << lenta_size << ", Синтаксический анализ выполнен без ошибок" << endl;
			rc = true;
			break;
		case SURPRISE:
			MFST_TRACE4("------> SURPRISE", rl)
				break;
		}
		return rc;
	}
	char* Mfst::getJSt(char* buf)	//формир ошибки синтаксич
	{
		for (int i = (signed)st.size() - 1; i >= 0; --i)
		{
			short p = st[i];
			buf[st.size() - 1 - i] = GRB::Rule::Chain::alphabet_to_char(p);
		}
		buf[st.size()] = 0x00;
		return buf;
	}
	char* Mfst::getCLenta(char* buf, short pos, short n)
	{
		short i, k = (pos + n < lenta_size) ? pos + n : lenta_size;
		for (i = pos; i < k; i++)
			buf[i - pos] = GRB::Rule::Chain::alphabet_to_char(lenta[i]);
		buf[i - pos] = 0x00;
		return buf;
	}
	char* Mfst::getDiagnosis(short n, char* buf)	//формир ошибки синтаксич
	{
		char* rc = { 0 };
		int errid = 0;
		int lpos = -1;
		if (n < MFST_DIAGN_NUMBER && (lpos = diagnosis[n].lenta_position) >= 0)
		{
			errid = grebach.getRule(diagnosis[n].nrule).iderror;
			Error::ERROR err = Error::geterror(errid, ERROR_ZERO_LINE, ERROR_ZERO_COL);
			/*cout << "Ошибка " << err.id << ":" << err.message<< " строка " << lexTable.table[lpos].sn << endl ;*/
			throw ERROR_THROW(err.id, lexTable.table[lpos].sn, lexTable.table[lpos].indxTI);
			rc = buf;
		}
		return rc;
	}
	void Mfst::printrules()		//вывести правила вывода
	{
		MfstState state;
		GRB::Rule rule;
		for (unsigned short i = 0; i < storestate.size(); i++)
		{
			state = storestate[i];
			rule = grebach.getRule(state.nrule);
			MFST_TRACE7(rl);
		}
	}
	bool Mfst::savededucation()	//сохранить вывести правила вывода
	{
		MfstState state;
		GRB::Rule rule;
		deducation.nrules = new short[deducation.size = storestate.size()];
		deducation.nrulechains = new short[deducation.size];
		for (unsigned short i = 0; i < storestate.size(); i++)
		{
			state = storestate[i];
			deducation.nrules[i] = state.nrule;
			deducation.nrulechains[i] = state.nrulechain;
		}
		return true;
	}
}
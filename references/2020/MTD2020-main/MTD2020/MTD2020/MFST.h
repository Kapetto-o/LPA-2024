#pragma once
#include "vector"
using namespace std;
#define MFST_TRACE_START *rl.stream << setw(4) << left << "Шаг:"\
							  << setw(20) << left << " Правило" \
							  << setw(30) << left << " Входная лента" \
							  << setw(20) << left << " Стек" << endl;
#define MFST_TRACE1	*rl.stream << setw(4) << left << ++FST_TRACE_n << ": "\
					     << setw(20) << left << rule.getCRule(rbuf, nrulechain)\
					     << setw(30) << left << getCLenta(lbuf, lenta_position)\
					     << setw(20) << left << getJSt(sbuf) << endl;
#define MFST_TRACE2	 *rl.stream << setw(4) << left << FST_TRACE_n << ": "\
					     << setw(20) << left << " "\
					     << setw(30) << left << getCLenta(lbuf, lenta_position)\
					     << setw(20) << left << getJSt(sbuf) << endl;
#define MFST_TRACE3	*rl.stream << setw(4) << left << ++FST_TRACE_n << ": "\
					     << setw(20) << left << " "\
					     << setw(30) << left << getCLenta(lbuf, lenta_position)\
					     << setw(20) << left << getJSt(sbuf) << endl;
#define MFST_TRACE4(c)	*rl.stream << setw(4) << left << ++FST_TRACE_n << ": " << setw(20) << left << c << endl;
#define MFST_TRACE5(c)	*rl.stream << setw(4) << left << FST_TRACE_n << ": " << setw(20) << left << c << endl;
#define MFST_TRACE6(c, k)	*rl.stream << setw(4) << left << FST_TRACE_n << ": " << setw(20) << left << c << k << endl;
#define MFST_TRACE7	*rl.stream << setw(4) << left << state.lenta_position<< ": "\
					     << setw(20) << left << rule.getCRule(rbuf, state.nrulechain) << endl;
#define MFST_DIAGN_MAXSIZE	3*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER	3
#include <stack>
typedef std::vector<short> MFSTSTSTACK;		// стек автомата

namespace MFST
{
	struct MfstState					//состояние автомата для сохранения
	{
		short lenta_position;			//позиция на ленте
		short nrule;					//номер текущего правила
		short nrulechain;				//номер текущей цепочки
		MFSTSTSTACK st;					//стек автомата
		MfstState();
		MfstState(
			short pposition,			//позиция на ленте
			MFSTSTSTACK pst,			//стек автомата
			short pnrulechain			//номер текущей цепочки, текущего правила
		);
		MfstState(
			short pposition,			//позиция на ленте
			MFSTSTSTACK pst,			//стек автомата
			short pnrule,				//номер текущего правила
			short pnrulechain);			//номер текущей цепочки, текущего правила
	};

	struct Rl
	{
		wchar_t rulefile[PARAMETER_MAX_SIZE];
		std::ofstream* stream;
	};

	static const Rl FIRSTINIT = { L"", NULL };		//для начальной инициализации ID
	Rl getrul(wchar_t rulefile[]);					//сформировать структуру ID
	void WriteData(Rl rl);							//время создания

	struct Mfst							//магазинный автомат			
	{
		enum RC_STEP					//код возврата функции step
		{
			NS_OK,						//найдено правило и цепочка, цепочка записана в стек
			NS_NORULE,					//не найдено правило грамматики (ошибки в грамматике)
			NS_NORULECHAIN,				//не наёдена подходящая цепочка правила (ошибка в исходном коде
			NS_ERROR,					//неизвестный нетерминальный символ грамматики
			TS_OK,						//текущий символ ленты == вершине стека, продвинулась лента, pop стека
			TS_NOK,						//текущий символ ленты != вершине стека, восстановлено состояние
			LENTA_END,					//текущая позиция ленты >= lenta_size
			SURPRISE					//неожиданный код возврата (ошибка в step)
		};

		struct MfstDiagnosis			//диагностика
		{
			short lenta_position;		//позиция на ленте
			RC_STEP rc_step;			//код завершения шага
			short nrule;				//номер правила
			short nrule_chain;			//номер цепочки правила
			MfstDiagnosis();
			MfstDiagnosis(				//диагностика
				short plenta_position,  //позиция на ленте
				RC_STEP prc_step,		//код завершения шага
				short pnrule,			//номер правила
				short pnrule_chain		//номер цепочки правила
			);
		} diagnosis[MFST_DIAGN_NUMBER]; //последние самые глубокие сообщения

		GRBALPHABET* lenta;				//перекодированная(TS/NS) лента (из LEX)
		short lenta_position;			//текущая позиция на ленте
		short nrule;					//номер текущего правила
		short nrulechain;				//номер текущей цепочки, текущего правила
		short lenta_size;				//размер ленты
		GRB::Greibach grebach;			//грамматика Грейбах
		LEX::LexTable lexTable;			//результат работы лексического анализатора
		MFSTSTSTACK st;						//стек автомата
		std::vector<MfstState> storestate; // стек для сохранения состояний

		Mfst();
		Mfst(
			LEX::LexTable plex,						//результат работы лексического анализатора
			GRB::Greibach pgrebach,					//грамматика Грейбах
			MFST::Rl rl
		);

		MFST::Rl rl;
		char* getJSt(char* buf);								//получить содержимое стека
		char* getCLenta(char* buf, short pos, short n = 25);	//лента: n символов с pos
		char* getDiagnosis(short n, char* buf);					//получить n-ую цепочку диагностики или 0x00
		bool savestate();										//сохранить состояние автомата
		bool reststate();								//восстановить состояние автомата
		bool push_chain(						//поместить цепочку правила в стек
			GRB::Rule::Chain chain				//цепочка правила
		);
		RC_STEP step();							//выполнить шаг автомата
		bool start();							//запустить автомат
		bool savediagnosis(
			RC_STEP pprc_step					//код завершения шага
		);
		void printrules();						//вывести последовательность правил

		struct Deducation						//вывод
		{
			short size;							//количество шагов в выводе
			short* nrules;						//номер правил грамматики
			short* nrulechains;					//номер цепочек правил (nrules)
			Deducation() { size = 0; nrules = 0; nrulechains = 0; }
		} deducation;

		bool savededucation();									//сохранить дерево вывода
	};
}
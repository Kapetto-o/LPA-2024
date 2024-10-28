#pragma once
#include "stdafx.h"
#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3

//�������
#define MFST_TRACE_START *(log.stream) << std::setfill(' ') << std::setw(4)<<std::left<<"���"<<":"  \
								  <<std::setw(20)<<std::left<<" �������" \
								  <<std::setw(30)<<std::left<<" ������� �����" \
								  <<std::setw(20)<<std::left<<" ����" \
								  <<std::endl;

static int FST_TRACE_n = -1;
static char rbuf[205], sbuf[205], lbuf[1024]; // ������

#define ISNS(n) GRB::Rule::Chain::isN(n)
#define MFST_TRACE1	*(log.stream) << std::setfill(' ')<<std::setw(4)<<std::left<<++FST_TRACE_n<<": " \
									<<std::setw(20)<<std::left<<rule.getCRule(rbuf, nrulechain)	\
									<<std::setw(30)<<std::left<<getCLenta(lbuf, lenta_position)	\
									<<std::setw(20)<<std::left<<getCSt(sbuf) \
									<<std::endl;

#define MFST_TRACE2	*(log.stream) << std::setfill(' ')<<std::setw(4)<<std::left<< FST_TRACE_n<<": " \
									<<std::setw(20)<<std::left<<" " \
									<<std::setw(30)<<std::left<<getCLenta(lbuf, lenta_position)	\
									<<std::setw(20)<<std::left<<getCSt(sbuf) \
									<<std::endl;

#define MFST_TRACE3	*(log.stream) << std::setfill(' ')<<std::setw(4)<<std::left<<++FST_TRACE_n<<": " \
									<<std::setw(20)<<std::left<<" " \
									<<std::setw(30)<<std::left<<getCLenta(lbuf, lenta_position)	\
									<<std::setw(20)<<std::left<<getCSt(sbuf) \
									<<std::endl;

#define MFST_TRACE4(c) *(log.stream) << std::setfill(' ')<<std::setw(4)<<std::left<<++FST_TRACE_n<<": "<<std::setw(20)<<std::left<<c<<std::endl;

#define MFST_TRACE5(c) *(log.stream) << std::setfill(' ')<<std::setw(4)<<std::left<< FST_TRACE_n<<": "<<std::setw(20)<<std::left<<c<<std::endl;

#define MFST_TRACE6(c, k)  *(log.stream) << std::setfill(' ')<<std::setw(4)<<std::left<< FST_TRACE_n<<": "<<std::setw(20)<<std::left<<c<<k<<std::endl;

#define MFST_TRACE7 *(log.stream) << std::setfill(' ')<<std::setw(4)<<std::left<<state.lenta_position<<": " \
								<<std::setw(20)<<std::left<<rule.getCRule(rbuf,state.nrulechain) \
								<<std::endl;


typedef std::vector<short> MFSTSTSTACK;		// ���� ��������
namespace MFST
{
	struct MfstState			// ��������� �������� (��� ����������)
	{
		short lenta_position;	// ������� �� �����
		short nrule;			// ����� �������� �������
		short nrulechain;		// ����� ������� �������, �������� �������
		MFSTSTSTACK st;			// ���� ��������
		MfstState();
		MfstState(
			short pposition,	// ������� �� �����
			MFSTSTSTACK pst,	// ���� ��������
			short pnrulechain	// ����� ������� �������, �������� �������
		);
		MfstState(
			short pposition,	// ������� �� �����
			MFSTSTSTACK pst,	// ���� ��������
			short pnrule,
			short pnrulechain	// ����� ������� �������, �������� �������
		);
	};

	struct Mfst		// ���������� �������
	{
		enum RC_STEP {	// ��� �������� ������� step
			NS_OK,		// ������� ������� � �������, ������� �������� � ����
			NS_NORULE,	// �� ������� ������� ���������� (������ � ����������)
			NS_NORULECHAIN,	// �� ������� ���������� ������� ������� (������ � �������� ����)
			NS_ERROR,	// ����������� �������������� ������ ����������
			TS_OK,		// ���. ������ ����� == ������� �����, ������������ �����, pop �����
			TS_NOK,		// ���. ������ ����� != ������� �����, ������������� ���������
			LENTA_END,	// ������� ������� ����� >= lenta_size
			SURPRISE	// ����������� ��� �������� (������ � step)
		};
		struct MfstDiagnosis		// �����������
		{
			short lenta_position;	// ������� �� �����
			RC_STEP rc_step;		// ��� ���������� ����
			short nrule;			// ����� �������
			short nrule_chain;		// ����� ������� �������
			MfstDiagnosis();
			MfstDiagnosis(
				short plenta_position, // ������� �� �����
				RC_STEP prc_step,	   // ��� ���������� ����
				short pnrule,		   // ����� �������
				short pnrule_chain	   // ����� ������� �������
			);
		}diagnosis[MFST_DIAGN_NUMBER];	// ��������� ����� �������� ���������

		GRBALPHABET* lenta;		// ���������������� (TS/NS) ����� (�� LEX)
		short lenta_position;	// ������� ������� �� �����
		short nrule;			// ����� �������� �������
		short nrulechain;		// ����� ������� �������, �������� �������
		short lenta_size;		// ������ �����
		GRB::Greibach greibach; // ���������� �������
		LT::LexTable lex;		// ��������� ������ ������. �����������
		MFSTSTSTACK st;			// ���� ��������
		std::vector<MfstState> storestate; // ���� ��� ���������� ���������
		Mfst();
		Mfst(
			LT::LexTable plex,	// ��������� ������ ������. �����������
			GRB::Greibach pgreibach // ���������� ������
		);
		char* getCSt(char* buf);	// �������� ���������� �����
		char* getCLenta(char* buf, short pos, short n = 25); // �����: n �������� � pos
		char* getDiagnosis(short n, char* buf);	// �������� n-�� ������ ����������� ��� 0x00
		bool saveState(Log::LOG log);			// ��������� ��������� ��������
		bool restState(Log::LOG log);			// ������������ ��������� ��������
		bool push_chain(			// ��������� ������� ������� � �����
			GRB::Rule::Chain chain	// ������� �������
		);
		RC_STEP step(Log::LOG log);				// ��������� ��� ��������
		bool start(Log::LOG &log, Parm::PARM& parm);				// ��������� �������
		bool saveDiagnosis(
			RC_STEP pprc_step		// ��� ���������� ����
		);
		void printRules(Log::LOG& log);			// ������� ������������������ ������

		struct Deducation			// �����
		{
			short size;				// ���-�� ����� � ������
			short* nrules;			// ������ ������ ����������
			short* nrulechains;		// ������ ������� ������ ���������� (nrules)
			Deducation() { size = 0; nrules = 0; nrulechains = 0; };
		}deducation;
		bool saveDeducation();		// ��������� ������ ������
	};
};
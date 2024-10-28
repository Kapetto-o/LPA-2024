#include "stdafx.h"
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	Log::LOG log = Log::FIRSTINIT;
	ID::Id id = ID::FIRSTINIT;
	LEX::Lex lx = LEX::FIRSTINIT;
	MFST::Rl rl = MFST::FIRSTINIT;
	Gen::Js js = Gen::FIRSTINIT;
	LEX::LexTable ltable = LEX::Create(LT_TABLE_SIZE);
	ID::IdTable itable = ID::Create(TI_TABLE_SIZE);
	try
	{
		Parameter::PARAMETER parametr = Parameter::getparametr(argc, argv);
		log = Log::getlog(parametr.log);
		id = ID::getid(parametr.id);
		lx = LEX::getlex(parametr.lx);
		rl = MFST::getrul(parametr.rl);
		js = Gen::getjs(parametr.js);
		Log::WriteData(log);
		Log::WriteParm(log, parametr);
		In::IN in = In::getin(parametr.in);
		Log::WriteIn(log, in);
		LA::Lexicalanaliz((char*)in.text, log, ltable, itable);
		LEX::WriteData(lx);
		LEX::WriteLex(lx, ltable);
		LEX::WriteLexem(lx, ltable);
		ID::WriteData(id);
		ID::WriteId(id, itable);
		MFST::WriteData(rl);
		MFST_TRACE_START(rl);
		MFST::Mfst mfst(ltable, GRB::getGreibach(), rl);
		mfst.start();
		mfst.savededucation();
		mfst.printrules();
		SA::RetValue(ltable, itable);
		SA::Parametrs(ltable);
		SA::TypeofParameters(ltable, itable);
		SA::TypeofFuncParm(ltable, itable);
		SA::InicialId(ltable, itable);
		SA::InicialL(ltable, itable);
		SA::Operation(ltable, itable);
		SA::Operationl(ltable, itable);
		SA::BoolLt(ltable, itable);
		Gen::StartGeneration(ltable, itable, js);
		PolishNotation(ltable, itable);
		LEX::WriteLex(lx, ltable);
		ID::Delete(itable);
		LEX::Delete(ltable);
		cout << "Протоколы созданы" << endl;
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
	Log::Close(log);
	LEX::Close(lx);
	ID::Close(id);
	system("pause");
	return 0;
}
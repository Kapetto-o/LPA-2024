#pragma once

namespace Gen
{
#define ALERT_BECAUSE_OF_MINUS    *js.stream << "if(" << ltable.table[j - 2].buf << "<0 ) " << "\n{alert('because of minus " << ltable.table[j - 2].buf <<  " becomes to zero');\n" << ltable.table[j - 2].buf << " = 0;}" << endl;
#define ALERT_BECAUSE_OF_NOT_INT	*js.stream << "if(!Number.isInteger(" << ltable.table[j-2].buf << ")){alert('not an Integer, " << ltable.table[j - 2].buf << " will be rouned'); " << ltable.table[j - 2].buf << "=Math.round(j);}\n" << endl;
//length_of_str + uwhole <255

	struct Js
	{
		wchar_t jsfile[PARAMETER_MAX_SIZE];
		std::ofstream* stream;
	};
	static const Js FIRSTINIT = { L"", NULL };//для начальной инициализации Js
	Js getjs(wchar_t jsfile[]);	//сформировать структуру Js
	void Head();
	void StartGeneration(LEX::LexTable& LEXable, ID::IdTable& itable, Gen::Js& js);
}
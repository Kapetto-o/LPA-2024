#include "CES-2020L.h"

extern "C"
{
	char* DATE(void)
	{
		time_t rawtime;
		struct tm timeinfo;
		char* buffer = (char*)calloc(SIZE, sizeof(char));
		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);
		strftime(buffer _Notnull_, SIZE, "Date: %d.%m.%y", &timeinfo);
		return buffer;
	}

	char* TIME(void)
	{
		time_t rawtime;
		struct tm timeinfo;
		char *buffer = (char*)calloc(SIZE, sizeof(char));
		time(&rawtime);
		localtime_s(&timeinfo, &rawtime);
		strftime(buffer _Notnull_, SIZE, "Time: %H:%M:%S", &timeinfo);
		return buffer;
	}

	void outStr(char* value)
	{
		system("chcp 1251 > nul");
		std::cout << value << std::endl;
	}

	void outUs(int value, int line = -1, int position = -1)
	{
		if(value <= USINT_MAXVALUE && value >= USINT_MINVALUE )
			std::cout << value << std::endl;
		else
		{
			std::system("cls");
			std::cout << TRACE_STR << std::endl;

			if (value == DIVISION_BY_ZERO)
			{
				std::cout << "Ошибка 303: [SemA] Деление на 0 в выражении, строка ";
				std::cout << line << ", позиция " << position << std::endl;
			}
			else
			{
				std::cout << "Ошибка 314: [SemA] Значение целочисленного литерала не входит в диапазон допустимых значений, ";
				std::cout << "строка " << line << ", позиция " << position << std::endl;
			}

			std::cout << TRACE_STR << std::endl;
		}	
	}

	void outBool(bool value)
	{
		std::cout.setf(std::ios::boolalpha);
		std::cout << value << std::endl;
		std::cout.unsetf(std::ios::boolalpha);
	}

	void outSymb(char value)
	{
		std::cout << value << std::endl;
	}
}
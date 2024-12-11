#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cctype>

extern "C"
{
	typedef char* str;

	str __stdcall strduplicate(str parm1, const str parm2) {
		if (parm1 == nullptr || parm2 == nullptr) {
			return nullptr;
		}
		std::strcpy(parm1, parm2);

		return parm1;
	}

	int __stdcall  strlength(const str parm1) {
		if (parm1 == nullptr) {
			return 0;
		}

		return std::strlen(parm1);
	}

	int strtransint(const str parm1) {
		if (parm1 == nullptr) {
			return -1; 
		}

		for (size_t i = 0; parm1[i] != '\0'; ++i) {
			if (!std::isdigit(parm1[i])) {
				return -1;
			}
		}

		int result = std::atoi(parm1);
		return result;
	}

	int __stdcall noutl(int value)
	{
		std::cout << value << std::endl;
		return 0;
	}
	int __stdcall soutl(char* ptr)
	{
		setlocale(LC_ALL, "Rus");
		if (ptr == nullptr)
		{
			std::cout << std::endl;
		}
		for (int i = 0; ptr[i] != '\0'; i++)
			std::cout << ptr[i];
		std::cout << std::endl;
		return 0;
	}
	int __stdcall SYSPAUSE()
	{
		system("pause");
		return 0;
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

extern "C"
{
    char* __stdcall _strduplicate(char* parm1, const char* parm2)
    {
        if (parm1 == nullptr || parm2 == nullptr) return nullptr;  // Проверка на nullptr
        strcpy(parm1, parm2);
        return parm1;
    }

    int __stdcall _strlength(const char* parm1)
    {
        if (parm1 == nullptr) return 0;
        return strlen(parm1);
    }

    int __stdcall _strtransint(const char* parm1)
    {
        if (parm1 == nullptr) return 0;

        for (int i = 0; parm1[i] != '\0'; i++)
        {
            if (!isdigit(parm1[i]))
            {
                std::cerr << "Error: String contains non-digit characters." << std::endl;
                return 0;
            }
        }
        return atoi(parm1);
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
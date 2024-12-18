#include "stdafx.h"
#include "CodeGeneration.h"

namespace CodeGeneration
{
    void CodeGeneration(LA::LEX lex, wchar_t outfile[])
    {
        ofstream generation(outfile);

        generation << START;
        generation << PROTOTYPES;

        generation << ".CONST\n";
        generation << "\tnull_division BYTE 'ERROR: DIVISION BY ZERO', 0\n";
        generation << "\tOVER_FLOW BYTE 'ERROR: OVERFLOW', 0\n";
        generation << "\ttrue BYTE 'true', 0\n";
        generation << "\tfalse BYTE 'false', 0\n";

        // Генерация литералов
        for (int i = 0; i < lex.idtable.size; i++)
        {
            if (lex.idtable.table[i].idType == IT::L)
            {
                generation << "\t" << lex.idtable.table[i].id;
                if (lex.idtable.table[i].idDataType == IT::STR)
                {
                    // Убираем лишние кавычки, если они уже есть в строке
                    string value = lex.idtable.table[i].value.vstr.str;
                    if (!value.empty() && value.front() == '"' && value.back() == '"')
                    {
                        value = value.substr(1, value.size() - 2); // Удаляем первые и последние кавычки
                    }

                    generation << " BYTE \"" << value << "\", 0\n";
                }
                else if (lex.idtable.table[i].idDataType == IT::SHORT)
                {
                    generation << " SDWORD " << lex.idtable.table[i].value.vshort << "\n";
                }
                else if (lex.idtable.table[i].idDataType == IT::CHAR)
                {
                    // CHAR литералы объявляются как одноэлементные массивы байтов с нулевым терминатором
                    generation << " BYTE '" << (char)lex.idtable.table[i].value.vchar << "', 0\n";
                }
                else
                {
                    generation << " DWORD " << lex.idtable.table[i].value.vshort << "\n";
                }
            }
        }

        generation << ".DATA\n";
        for (int i = 0; i < lex.idtable.size; i++)
        {
            if (lex.idtable.table[i].idType == IT::IDTYPE::V)
            {
                generation << "\t" << lex.idtable.table[i].id;
                if (lex.idtable.table[i].idDataType == IT::BOOL)
                {
                    generation << " DWORD 0\n";
                }
                else if (lex.idtable.table[i].idDataType == IT::STR)
                {
                    generation << " DWORD ?\n";
                }
                else if (lex.idtable.table[i].idDataType == IT::CHAR)
                {
                    generation << " BYTE 0, 0\n";
                }
                else if (lex.idtable.table[i].idDataType == IT::SHORT)
                {
                    generation << " SDWORD 0\n";
                }
                else
                {
                    generation << " DWORD 0\n";
                }
            }
        }

        stack<int> cycleStack;
        int num_of_cycle = 0;

        int num_of_ret = 0,
            num_of_boolCompare = 0;
        string func_name = "";
        bool flag_func = false,
            flag_return = false,
            flag_main = false;

        generation << "\n.CODE\n\n";

        for (int i = 0; i < lex.lextable.size; i++)
        {
            switch (lex.lextable.table[i].lexema)
            {
            case LEX_FUNCTION:
            {
                // Следующий токен должен быть имя функции
                i++;
                func_name = lex.idtable.table[lex.lextable.table[i].idxTI].id;
                i++;
                while (lex.lextable.table[i].lexema != LEX_LEFTHESIS_OPEN && i < lex.lextable.size) i++;

                generation << func_name << " PROC";

                i++; // пропускаем '('
                bool firstParam = true;
                while (lex.lextable.table[i].lexema != LEX_RIGHTHESIS_CLOSE && i < lex.lextable.size)
                {
                    if (lex.lextable.table[i].lexema == LEX_IDENTIFIER &&
                        lex.idtable.table[lex.lextable.table[i].idxTI].idType == IT::P)
                    {
                        if (firstParam)
                        {
                            generation << " ";
                            firstParam = false;
                        }
                        else
                        {
                            generation << ", ";
                        }
                        generation << lex.idtable.table[lex.lextable.table[i].idxTI].id << " : ";
                        switch (lex.idtable.table[lex.lextable.table[i].idxTI].idDataType)
                        {
                        case IT::SHORT:
                            generation << "SDWORD";
                            break;
                        case IT::STR:
                            generation << "DWORD";
                            break;
                        case IT::CHAR:
                            generation << "DWORD"; // Обрабатывается как одноэлементный массив байтов
                            break;
                        case IT::BOOL:
                            generation << "DWORD";
                            break;
                        default:
                            generation << "DWORD";
                            break;
                        }
                    }
                    i++;
                }
                i++;
                generation << "\n";
                flag_func = true;
            }
            break;
            case LEX_MAIN:
            {
                generation << "main PROC\n";
                flag_main = true;
            }
            break;
            case LEX_EQUALS:
            {
                int result_position = i - 1;
                while (lex.lextable.table[i].lexema != LEX_SEMICOLON)
                {
                    switch (lex.lextable.table[i].lexema)
                    {
                    case LEX_STRDUPLICATE:
                        generation << "\tcall _strduplicate\n\tpush eax\n";
                        break;
                    case LEX_STRLENGTH:
                        generation << "\tcall _strlength\n\tpush eax\n";
                        break;
                    case LEX_STRTRANSINT:
                        generation << "\tcall _strtransint\n\tpush eax\n";
                        break;
                    case LEX_LITERAL:
                    {
                        if (lex.idtable.table[lex.lextable.table[i].idxTI].idDataType == IT::STR)
                        {
                            generation << "\tpush offset " << lex.idtable.table[lex.lextable.table[i].idxTI].id << "\n";
                        }
                        else
                        {
                            // Для CHAR, push offset для одноэлементного массива байтов
                            if (lex.idtable.table[lex.lextable.table[i].idxTI].idDataType == IT::CHAR)
                            {
                                generation << "\tpush offset " << lex.idtable.table[lex.lextable.table[i].idxTI].id << "\n";
                            }
                            else
                            {
                                generation << "\tpush " << lex.idtable.table[lex.lextable.table[i].idxTI].id << "\n";
                            }
                        }
                        break;
                    }
                    case LEX_IDENTIFIER:
                    {
                        if (lex.idtable.table[lex.lextable.table[i].idxTI].idType == IT::F)
                        {
                            generation << "\tcall " << lex.idtable.table[lex.lextable.table[i].idxTI].id << "\n\tpush eax\n";
                        }
                        else
                        {
                            // Если идентификатор - это CHAR, используем offset
                            if (lex.idtable.table[lex.lextable.table[i].idxTI].idDataType == IT::CHAR)
                            {
                                generation << "\tpush offset " << lex.idtable.table[lex.lextable.table[i].idxTI].id << "\n";
                            }
                            else
                            {
                                generation << "\tpush " << lex.idtable.table[lex.lextable.table[i].idxTI].id << "\n";
                            }
                        }
                        break;
                    }
                    case LEX_MULTIPLICATION:
                        generation << "\tpop eax\n\tpop ebx\n";
                        generation << "\tmul ebx\n\tpush eax\n";
                        break;
                    case LEX_ADDITION:
                        generation << "\tpop eax\n\tpop ebx\n";
                        generation << "\tadd eax, ebx\n\tpush eax\n";
                        break;
                    case LEX_SUBSTRACTION:
                        generation << "\tpop ebx\n\tpop eax\n";
                        generation << "\tsub eax, ebx\n\tpush eax\n";
                        break;
                    case LEX_DIVISION:
                        generation << "\tpop ebx\n\tpop eax\n";
                        generation << "\tcmp ebx,0\n\tje SOMETHINGWRONG\n";
                        generation << "\tcdq\n";
                        generation << "\tidiv ebx\n\tpush eax\n";
                        break;
                    case LEX_REMAINDERDIVISION:
                        generation << "\tpop ebx\n\tpop eax\n";
                        generation << "\tcmp ebx,0\n\tje SOMETHINGWRONG\n";
                        generation << "\tcdq\n";
                        generation << "\tidiv ebx\n\tpush edx\n";
                        break;
                    default:
                        break;
                    }
                    i++;
                }

                if (lex.idtable.table[lex.lextable.table[result_position].idxTI].idDataType == IT::SHORT)
                {
                    generation << "\tpop eax\n";
                    generation << "\tcmp eax, 32767\n";
                    generation << "\tjg overflow\n";
                    generation << "\tcmp eax, -32768\n";
                    generation << "\tjl overflow\n";
                    generation << "\tmov " << lex.idtable.table[lex.lextable.table[result_position].idxTI].id << ", eax\n";
                }
                else if (lex.idtable.table[lex.lextable.table[result_position].idxTI].idDataType == IT::CHAR)
                {
                    generation << "\tpop eax\n";            // Получаем значение из стека
                    generation << "\tmov byte ptr ["
                        << lex.idtable.table[lex.lextable.table[result_position].idxTI].id
                        << "], al\n";                // Сохраняем только младший байт
                }
                else
                {
                    generation << "\tpop " << lex.idtable.table[lex.lextable.table[result_position].idxTI].id << "\n";
                }
                break;
            }
            case LEX_RETURN:
            {
                generation << "\tpush ";
                i++;
                if (lex.idtable.table[lex.lextable.table[i].idxTI].idType == IT::L &&
                    lex.idtable.table[lex.lextable.table[i].idxTI].idDataType == IT::STR)
                {
                    // Для строки, получаем значение из стека
                    generation << "\tmov eax, [esp + 4] ; Получаем параметр " << lex.idtable.table[lex.lextable.table[i++].idxTI].id << "\n";
                    generation << "\tpush eax\n";
                }
                else if (lex.idtable.table[lex.lextable.table[i].idxTI].idType == IT::L &&
                    lex.idtable.table[lex.lextable.table[i].idxTI].idDataType == IT::SHORT)
                {
                    generation << lex.idtable.table[lex.lextable.table[i++].idxTI].value.vshort << "\n";
                }
                else
                {
                    // Обработка CHAR
                    if (lex.idtable.table[lex.lextable.table[i].idxTI].idDataType == IT::CHAR)
                    {
                        string varName = lex.idtable.table[lex.lextable.table[i].idxTI].id;
                        generation << "\tmov eax, [esp + 4] ; Получаем параметр " << varName << "\n";
                        generation << "\tpush eax\n";
                        i++;
                    }
                    else
                    {
                        generation << lex.idtable.table[lex.lextable.table[i++].idxTI].id << "\n";
                    }
                }
                if (flag_func)
                {
                    generation << "\tjmp local" << num_of_ret << "\n";
                    flag_return = true;
                }
                if (flag_main)
                {
                    generation << "\tjmp theend\n";
                    flag_return = true;
                }
                break;
            }
            case LEX_RIGHTBRACE_CLOSE:
            {
                // Закрываем тело цикла если он есть
                if (!cycleStack.empty())
                {
                    int currentCycle = cycleStack.top();
                    generation << "\tjmp cycle" << currentCycle << "\n";
                    generation << "cycleEnd" << currentCycle << ":\n";
                    cycleStack.pop();
                }

                // Закрываем функцию, если встречаем '}' и следующий ';'
                if (flag_func && lex.lextable.table[i + 1].lexema == LEX_SEMICOLON)
                {
                    if (flag_return)
                    {
                        generation << "local" << num_of_ret++ << ":\n";
                        generation << "\tpop eax\n\tret\n";
                        flag_return = false;
                    }
                    generation << func_name << " ENDP\n\n";
                    flag_func = false;
                }

                // Закрываем main, если это main и следующий символ ';'
                if (flag_main && !flag_func && lex.lextable.table[i + 1].lexema == LEX_SEMICOLON)
                {
                    if (flag_return)
                    {
                        generation << "theend:\n";
                        flag_return = false;
                    }
                    generation << FINISH;
                    flag_main = false;
                }
                break;
            }
            case LEX_CYCLE:
            {
                num_of_cycle++;
                cycleStack.push(num_of_cycle);
                generation << "cycle" << num_of_cycle << ":\n";
                break;
            }
            case LEX_LEFTHESIS_OPEN:
            {
                // Если перед этим был цикл, генерируем проверку условия
                if (!cycleStack.empty() && lex.lextable.table[i - 1].lexema == LEX_CYCLE)
                {
                    int currentCycle = cycleStack.top();
                    string leftVar = lex.idtable.table[lex.lextable.table[i + 1].idxTI].id;
                    string rightVar = lex.idtable.table[lex.lextable.table[i + 3].idxTI].id;
                    generation << "\tmov eax, " << leftVar << "\n";
                    generation << "\tcmp eax, " << rightVar << "\n";

                    switch (lex.lextable.table[i + 2].lexema)
                    {
                    case LEX_MORE:
                        generation << "\tjle cycleEnd" << currentCycle << "\n";
                        break;
                    case LEX_LESS:
                        generation << "\tjge cycleEnd" << currentCycle << "\n";
                        break;
                    case LEX_INEQUALITY:
                        generation << "\tjz cycleEnd" << currentCycle << "\n";
                        break;
                    case LEX_NOTEQUALS:
                        generation << "\tjnz cycleEnd" << currentCycle << "\n";
                        break;
                    case LEX_MOREEQUAL:
                        generation << "\tjl cycleEnd" << currentCycle << "\n";
                        break;
                    case LEX_LESSEQUAL:
                        generation << "\tjg cycleEnd" << currentCycle << "\n";
                        break;
                    default:
                        break;
                    }
                }
                break;
            }
            case LEX_WRITELINE:
            case LEX_WRITE:
            {
                switch (lex.idtable.table[lex.lextable.table[i + 1].idxTI].idDataType)
                {
                case IT::SHORT:
                    generation << "\npush " << lex.idtable.table[lex.lextable.table[i + 1].idxTI].id << "\ncall noutl\n";
                    break;
                case IT::BOOL:
                {
                    string varName = lex.idtable.table[lex.lextable.table[i + 1].idxTI].id;
                    generation << "\tmov eax, " << varName << "\n";
                    generation << "\tcmp eax, 0\n";
                    generation << "\tjz " << varName << num_of_boolCompare << "T\n";
                    generation << "\tjnz " << varName << num_of_boolCompare << "F\n";
                    generation << "\n" << varName << num_of_boolCompare << "T:\n";
                    generation << "\tpush offset false\ncall soutl\n";
                    generation << "\tjmp " << varName << num_of_boolCompare << "\n";
                    generation << "\n" << varName << num_of_boolCompare << "F:\n";
                    generation << "\tpush offset true\ncall soutl\n";
                    generation << "\n" << varName << num_of_boolCompare << ":\n";
                    num_of_boolCompare++;
                    break;
                }
                case IT::STR:
                {
                    string varName = lex.idtable.table[lex.lextable.table[i + 1].idxTI].id;
                    // Если это литерал (.CONST) или переменная, используем offset
                    generation << "\npush offset " << varName << "\ncall soutl\n";
                    break;
                }
                case IT::CHAR:
                {
                    string varName = lex.idtable.table[lex.lextable.table[i + 1].idxTI].id;
                    // Обработка char как одноэлементной строки
                    generation << "\tpush offset " << varName << "\ncall soutl\n";
                    break;
                }
                default:
                    break;
                }
                break;
            }
            }
        }
        generation.close();
    }
}
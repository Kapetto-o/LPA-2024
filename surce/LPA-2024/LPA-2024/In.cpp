#include "stdafx.h"
#include "In.h"
#include "Error.h"
#include <fstream>
#include <string>
#include <iostream>

namespace In
{
    unsigned char c = ':';

    IN GetIn(wchar_t infile[], wchar_t outfile[])
    {
        int currentLine = 0, currentCol = 0;
        IN Info{ 0, 0, 0, nullptr, IN_CODE_TABLE };
        std::ifstream in(infile);
        if (in.fail())
            throw ERROR_THROW(20);

        std::string fulltext;
        std::string temp;
        while (!in.eof())
        {
            Info.lines++;

            std::getline(in, temp);
            temp += '\n';
            fulltext += temp;
        }

        Info.text = new unsigned char[fulltext.size() + 1];
        unsigned char* Ptemp = Info.text;

        for (int i = 0; i < fulltext.size(); ++i)
        {
            unsigned char currentChar = fulltext[i];
            int charType = Info.code[currentChar];

            if (charType == IN::F)
            {
                throw ERROR_THROW_IN(110, currentLine, currentCol);
            }
            else if (charType == IN::I)
            {
                ++Info.ignor;
            }
            else if (charType == IN::T || charType == IN::P || charType == IN::N || charType == IN::S)
            {
                *Ptemp = currentChar;
                ++Ptemp;
            }
            else
            {
                *Ptemp = charType;
                ++Ptemp;
            }

            if (currentChar == '\n')
            {
                ++currentLine;
                currentCol = 0;
            }
            else
            {
                ++currentCol;
            }
        }

        *Ptemp = IN_CODE_ENDL;
        Info.size = strlen((char*)Info.text) - Info.lines;

        in.close();
        return Info;
    }
}
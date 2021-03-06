/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        core/CConsoleLogger.h
 *  PURPOSE:     Header file for console logger class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#include "CSingleton.h"
#include <fstream>
#include <string>

class CConsoleLogger : public CSingleton<CConsoleLogger>
{
public:
    CConsoleLogger();
    ~CConsoleLogger();

    void        LinePrintf(const char* szFormat, ...);
    void        WriteLine(const std::string& strLine);
    static void CleanLine(SString& strLine);
    static int  ReplaceNextWord(SString& strLine, int iPos, const char* szBlanker);

private:
    std::string  m_strFilename;
    FILE*        m_pFile;
    std::fstream File;
};

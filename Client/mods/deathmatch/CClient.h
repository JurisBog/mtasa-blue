/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/CClient.h
 *  PURPOSE:     Header file for Client class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#include <core/CClientBase.h>

class CClient : public CClientBase
{
public:
    int  ClientInitialize(const char* szArguments, CCoreInterface* pCore);
    void ClientShutdown(void);

    void PreFrameExecutionHandler(void);
    void PreHUDRenderExecutionHandler(bool bDidUnminimize, bool bDidRecreateRenderTargets);
    void PostFrameExecutionHandler(void);
    void IdleHandler(void);
    void RestreamModel(unsigned short usModel);

    bool WebsiteRequestResultHandler(const std::unordered_set<SString>& newPages);

    bool ProcessCommand(const char* szCommandLine);
    // bool        ProcessInput                    ( CInputMessage* pInputMessage );

    bool HandleException(CExceptionInformation* pExceptionInformation);
    void GetPlayerNames(std::vector<SString>& vPlayerNames);
};

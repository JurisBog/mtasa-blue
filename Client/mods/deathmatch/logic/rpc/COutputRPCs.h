/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/rpc/COutputRPCs.h
 *  PURPOSE:     Header for output RPC class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#include "CRPCFunctions.h"

class COutputRPCs : public CRPCFunctions
{
public:
    static void LoadFunctions(void);

    DECLARE_RPC(ToggleDebugger);
};

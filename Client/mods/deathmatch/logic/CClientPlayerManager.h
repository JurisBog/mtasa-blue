/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *               (Shared logic for modifications)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/shared_logic/CClientPlayerManager.h
 *  PURPOSE:     Player entity manager class header
 *
 *****************************************************************************/

// ## TODO ## : Make it possible to delete the local player without crashin ( m_pLocalPlayer not NULL-ed )

#pragma once

#include <list>

class CClientManager;
class CClientPlayer;
class CPlayerPed;

class CClientPlayerManager
{
    friend class CClientManager;
    friend class CClientPlayer;

public:
    CClientPlayer* GetLocalPlayer(void) { return m_pLocalPlayer; };
    void           SetLocalPlayer(CClientPlayer* pPlayer) { m_pLocalPlayer = pPlayer; };

    void DoPulse(void);
    void DeleteAll(void);

    unsigned int          Count(void) { return static_cast<unsigned int>(m_Players.size()); };
    static CClientPlayer* Get(ElementID ID);
    CClientPlayer*        Get(const char* szNick, bool bCaseSensitive = false);
    CClientPlayer*        Get(CPlayerPed* pPlayer, bool bValidatePointer);

    bool Exists(CClientPlayer* pPlayer);

    static bool IsPlayerLimitReached(void);

    std::vector<CClientPlayer*>::const_iterator IterBegin(void) { return m_Players.begin(); };
    std::vector<CClientPlayer*>::const_iterator IterEnd(void) { return m_Players.end(); };

    static bool IsValidModel(unsigned long ulModel);

    void ResetAll(void);

private:
    CClientPlayerManager(CClientManager* pManager);
    ~CClientPlayerManager(void);

    void AddToList(CClientPlayer* pPlayer) { m_Players.push_back(pPlayer); };
    void RemoveFromList(CClientPlayer* pPlayer);

    CClientManager*              m_pManager;
    bool                         m_bCanRemoveFromList;
    CMappedArray<CClientPlayer*> m_Players;
    CClientPlayer*               m_pLocalPlayer;
};

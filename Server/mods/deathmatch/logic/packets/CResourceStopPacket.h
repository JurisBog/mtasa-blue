/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        mods/deathmatch/logic/packets/CResourceStopPacket.h
 *  PURPOSE:     Resource stop packet handler class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#pragma once

#include "../packets/CPacket.h"

class CResourceStopPacket : public CPacket
{
public:
    CResourceStopPacket(unsigned short usID);

    ePacketID     GetPacketID(void) const { return PACKET_ID_RESOURCE_STOP; };
    unsigned long GetFlags(void) const { return PACKET_HIGH_PRIORITY | PACKET_RELIABLE | PACKET_SEQUENCED; };

    bool Write(NetBitStreamInterface& BitStream) const;

private:
    unsigned short m_usID;
};

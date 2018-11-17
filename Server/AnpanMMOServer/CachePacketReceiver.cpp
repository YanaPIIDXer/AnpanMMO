#include "stdafx.h"
#include "CachePacketReceiver.h"
#include "CacheServerConnection.h"

// �R���X�g���N�^
CachePacketReceiver::CachePacketReceiver(CacheServerConnection *pInParent)
	: pParent(pInParent)
{
}

// �p�P�b�g��M.
void CachePacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// �p�P�b�g��M�֐���ǉ�.
void CachePacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}

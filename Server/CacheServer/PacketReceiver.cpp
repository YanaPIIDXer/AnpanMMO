#include "stdafx.h"
#include "PacketReceiver.h"
#include "GameServerConnection.h"

// �R���X�g���N�^
PacketReceiver::PacketReceiver(GameServerConnection *pInParent)
	: pParent(pInParent)
{
}

// �p�P�b�g��M.
void PacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// �p�P�b�g��M�֐���ǉ�.
void PacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}

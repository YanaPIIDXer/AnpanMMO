#include "stdafx.h"
#include "WordCheckPacketReceiver.h"
#include "WordCheckServerConnection.h"
#include "ClientManager.h"

// �R���X�g���N�^
WordCheckPacketReceiver::WordCheckPacketReceiver(WordCheckServerConnection *pInParent)
	: pParent(pInParent)
{
}

// �p�P�b�g��M.
void WordCheckPacketReceiver::RecvPacket(PacketID ID, MemoryStreamInterface *pStream)
{
	if (PacketFuncs.find(ID) == PacketFuncs.end()) { return; }
	PacketFuncs[ID](pStream);
}


// �p�P�b�g��M�֐���ǉ�.
void WordCheckPacketReceiver::AddPacketFunc(PacketID ID, const PacketFunc &Func)
{
	PacketFuncs[ID] = Func;
}

/**
 * @file ClientStateBase.cpp
 * @brief �N���C�A���g�X�e�[�g���N���X
 * @author YanaP
 */
#include "stdafx.h"
#include "ClientStateBase.h"

// �p�P�b�g���.
void ClientStateBase::AnalyzePacket(u8 ID, MemoryStreamInterface *pStream)
{
	FunctionMap::iterator It = PacketFunctions.find(ID);
	if(It != PacketFunctions.end())
	{
		if (!It->second(pParent, pStream))
		{
			std::cout << "PacketID:" << (int)ID << " Serialize Error!" << std::endl;
		}
	}
}

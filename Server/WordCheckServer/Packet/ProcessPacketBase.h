#ifndef __CACHEPACKETBASE_H__
#define __CACHEPACKETBASE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"

/**
 * ���v���Z�X�Ƃ̒ʐM�p�p�P�b�g�x�[�X�N���X
 */
class ProcessPacketBase : public PacketBase
{

public:

	// �N���C�A���g�h�c
	u32 ClientId;

	// �V���A���C�Y
	virtual bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ClientId);
		return true;
	}

private:

};

#endif		// #ifndef __CACHEPACKETBASE_H__

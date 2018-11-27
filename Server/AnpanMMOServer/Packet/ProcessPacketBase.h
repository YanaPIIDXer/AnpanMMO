#ifndef __CACHEPACKETBASE_H__
#define __CACHEPACKETBASE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"

/**
 * 他プロセスとの通信用パケットベースクラス
 */
class ProcessPacketBase : public PacketBase
{

public:

	// クライアントＩＤ
	u32 ClientId;

	// シリアライズ
	virtual bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ClientId);
		return true;
	}

private:

};

#endif		// #ifndef __CACHEPACKETBASE_H__

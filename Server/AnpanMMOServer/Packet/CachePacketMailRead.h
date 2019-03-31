/**
 * @file CachePacketMailRead.h
 * @brief メール開封パケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETMAILREAD_H__
#define __CACHEPACKETMAILREAD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief メール開封パケット
 */
class CachePacketMailRead  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheMailRead; }

	

	//! ＩＤ
	u32 Id;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketMailRead()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketMailRead(u32 InClientId, u32 InId)
	{
		ClientId = InClientId;
		Id = InId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Id);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETMAILREAD_H__

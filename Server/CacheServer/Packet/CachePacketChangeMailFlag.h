/**
 * @file CachePacketChangeMailFlag.h
 * @brief メールフラグ切り替えパケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCHANGEMAILFLAG_H__
#define __CACHEPACKETCHANGEMAILFLAG_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief メールフラグ切り替えパケット
 */
class CachePacketChangeMailFlag  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheChangeMailFlag; }

	

	//! ＩＤ
	u32 Id;
	//! フラグ
	u8 Flag;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketChangeMailFlag()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketChangeMailFlag(u32 InClientId, u32 InId, u8 InFlag)
	{
		ClientId = InClientId;
		Id = InId;
		Flag = InFlag;
		
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
		pStream->Serialize(&Flag);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHANGEMAILFLAG_H__

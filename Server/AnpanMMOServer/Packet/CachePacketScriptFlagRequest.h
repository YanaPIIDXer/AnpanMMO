/**
 * @file CachePacketScriptFlagRequest.h
 * @brief スクリプトフラグリクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSCRIPTFLAGREQUEST_H__
#define __CACHEPACKETSCRIPTFLAGREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief スクリプトフラグリクエスト
 */
class CachePacketScriptFlagRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheScriptFlagRequest; }

	

	//! 
u32 CharacterId;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketScriptFlagRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketScriptFlagRequest(u32 InClientId, u32 InCharacterId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSCRIPTFLAGREQUEST_H__

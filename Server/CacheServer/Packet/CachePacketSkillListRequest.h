/**
 * @file CachePacketSkillListRequest.h
 * @brief スキルリストリクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSKILLLISTREQUEST_H__
#define __CACHEPACKETSKILLLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief スキルリストリクエスト
 */
class CachePacketSkillListRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSkillListRequest; }

	

	//! キャラクタＩＤ
	u32 CharacterId;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSkillListRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSkillListRequest(u32 InClientId, u32 InCharacterId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSKILLLISTREQUEST_H__

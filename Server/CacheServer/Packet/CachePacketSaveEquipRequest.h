/**
 * @file CachePacketSaveEquipRequest.h
 * @brief 装備保存リクエストパケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVEEQUIPREQUEST_H__
#define __CACHEPACKETSAVEEQUIPREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief 装備保存リクエストパケット
 */
class CachePacketSaveEquipRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveEquipRequest; }

	

	//! キャラクタID
	u32 CharacterId;
	//! 右手装備
	u32 RightEquip;
	//! 左手装備
	u32 LeftEquip;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSaveEquipRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSaveEquipRequest(u32 InClientId, u32 InCharacterId, u32 InRightEquip, u32 InLeftEquip)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		RightEquip = InRightEquip;
		LeftEquip = InLeftEquip;
		
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
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&RightEquip);
		pStream->Serialize(&LeftEquip);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEEQUIPREQUEST_H__

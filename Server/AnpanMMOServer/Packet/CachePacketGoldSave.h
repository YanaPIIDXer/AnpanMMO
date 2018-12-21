/**
 * @file CachePacketGoldSave.h
 * @brief ゴールド保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETGOLDSAVE_H__
#define __CACHEPACKETGOLDSAVE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ゴールド保存リクエスト
 */
class CachePacketGoldSave  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheGoldSave; }

	

	//! キャラクタＩＤ
	u32 CharacterId;
	//! ゴールド
	u32 Gold;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketGoldSave()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketGoldSave(u32 InClientId, u32 InCharacterId, u32 InGold)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		Gold = InGold;
		
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
		pStream->Serialize(&Gold);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETGOLDSAVE_H__

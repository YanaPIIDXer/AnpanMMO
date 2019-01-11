/**
 * @file CachePacketSaveEquipResponse.h
 * @brief 装備保存レスポンスパケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVEEQUIPRESPONSE_H__
#define __CACHEPACKETSAVEEQUIPRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief 装備保存レスポンスパケット
 */
class CachePacketSaveEquipResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveEquipResponse; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! リザルトコード
	u8 Result;
	//! 右手装備
	u32 RightEquip;
	//! 左手装備
	u32 LeftEquip;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSaveEquipResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSaveEquipResponse(u32 InClientId, u8 InResult, u32 InRightEquip, u32 InLeftEquip)
	{
		ClientId = InClientId;
		Result = InResult;
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
		pStream->Serialize(&Result);
		pStream->Serialize(&RightEquip);
		pStream->Serialize(&LeftEquip);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEEQUIPRESPONSE_H__

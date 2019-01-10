/**
 * @file PacketChangeEquipResult.h
 * @brief 装備変更結果パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETCHANGEEQUIPRESULT_H__
#define __PACKETCHANGEEQUIPRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 装備変更結果パケット
 */
class PacketChangeEquipResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ChangeEquipResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! 右手装備は外せない
		CanNotRemoveRightEquip,
		//! 所持していない
		NotPossession,
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
	PacketChangeEquipResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketChangeEquipResult(u8 InResult, u32 InRightEquip, u32 InLeftEquip)
	{
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
		pStream->Serialize(&Result);
		pStream->Serialize(&RightEquip);
		pStream->Serialize(&LeftEquip);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCHANGEEQUIPRESULT_H__

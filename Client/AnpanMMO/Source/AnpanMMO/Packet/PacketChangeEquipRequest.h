/**
 * @file PacketChangeEquipRequest.h
 * @brief 装備変更リクエストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETCHANGEEQUIPREQUEST_H__
#define __PACKETCHANGEEQUIPREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 装備変更リクエストパケット
 */
class PacketChangeEquipRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ChangeEquipRequest; }

	

	//! 右手装備
	u32 RightEquip;
	//! 左手装備
	u32 LeftEquip;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketChangeEquipRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketChangeEquipRequest(u32 InRightEquip, u32 InLeftEquip)
	{
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
		pStream->Serialize(&RightEquip);
		pStream->Serialize(&LeftEquip);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCHANGEEQUIPREQUEST_H__

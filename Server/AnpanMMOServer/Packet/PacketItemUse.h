/**
 * @file PacketItemUse.h
 * @brief アイテム使用
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMUSE_H__
#define __PACKETITEMUSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテム使用
 */
class PacketItemUse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemUse; }

	

	//! アイテムＩＤ
	u32 ItemId;
	//! ターゲットタイプ
	u8 TargetType;
	//! ターゲットのＵＵＩＤ
	u32 TargetUuid;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketItemUse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketItemUse(u32 InItemId, u8 InTargetType, u32 InTargetUuid)
	{
		ItemId = InItemId;
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId);
		pStream->Serialize(&TargetType);
		pStream->Serialize(&TargetUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMUSE_H__

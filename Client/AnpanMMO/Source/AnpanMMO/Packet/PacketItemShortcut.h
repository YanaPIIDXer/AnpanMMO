/**
 * @file PacketItemShortcut.h
 * @brief ログイン時アイテムショートカット通知
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMSHORTCUT_H__
#define __PACKETITEMSHORTCUT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ログイン時アイテムショートカット通知
 */
class PacketItemShortcut  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemShortcut; }

	

	//! アイテムＩＤ１
	u32 ItemId1;
	//! アイテムＩＤ２
	u32 ItemId2;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketItemShortcut()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketItemShortcut(u32 InItemId1, u32 InItemId2)
	{
		ItemId1 = InItemId1;
		ItemId2 = InItemId2;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId1);
		pStream->Serialize(&ItemId2);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMSHORTCUT_H__

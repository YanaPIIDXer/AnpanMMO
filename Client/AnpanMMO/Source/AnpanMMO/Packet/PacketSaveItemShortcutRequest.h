/**
 * @file PacketSaveItemShortcutRequest.h
 * @brief アイテムショートカット保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETSAVEITEMSHORTCUTREQUEST_H__
#define __PACKETSAVEITEMSHORTCUTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテムショートカット保存リクエスト
 */
class PacketSaveItemShortcutRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SaveItemShortcutRequest; }

	

	//! 
u32 ItemId1;
	//! 
u32 ItemId2;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSaveItemShortcutRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSaveItemShortcutRequest(u32 InItemId1, u32 InItemId2)
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

#endif		// #ifndef __PACKETSAVEITEMSHORTCUTREQUEST_H__

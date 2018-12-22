/**
 * @file PacketSaveItemShortcutResult.h
 * @brief アイテムショートカット保存結果
 * @author NativePacketGenerator
 */

#ifndef __PACKETSAVEITEMSHORTCUTRESULT_H__
#define __PACKETSAVEITEMSHORTCUTRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテムショートカット保存結果
 */
class PacketSaveItemShortcutResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SaveItemShortcutResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! 結果
	u8 Result;
	//! アイテムＩＤ１
	u32 ItemId1;
	//! アイテムＩＤ２
	u32 ItemId2;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSaveItemShortcutResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSaveItemShortcutResult(u8 InResult, u32 InItemId1, u32 InItemId2)
	{
		Result = InResult;
		ItemId1 = InItemId1;
		ItemId2 = InItemId2;
		
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
		pStream->Serialize(&ItemId1);
		pStream->Serialize(&ItemId2);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVEITEMSHORTCUTRESULT_H__

/**
 * @file PacketNPCTalkSelection.h
 * @brief 選択肢を選択
 * @author NativePacketGenerator
 */

#ifndef __PACKETNPCTALKSELECTION_H__
#define __PACKETNPCTALKSELECTION_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 選択肢を選択
 */
class PacketNPCTalkSelection  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::NPCTalkSelection; }

	

	//! 選択肢インデックス
	s32 Index;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketNPCTalkSelection()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketNPCTalkSelection(s32 InIndex)
	{
		Index = InIndex;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Index);
		
		return true;
	}
};

#endif		// #ifndef __PACKETNPCTALKSELECTION_H__

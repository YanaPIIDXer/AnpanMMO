/**
 * @file PacketScriptFlag.h
 * @brief スクリプトフラグ
 * @author NativePacketGenerator
 */

#ifndef __PACKETSCRIPTFLAG_H__
#define __PACKETSCRIPTFLAG_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スクリプトフラグ
 */
class PacketScriptFlag  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ScriptFlag; }

	

	//! ビットフィールド１
	u32 BitField1;
	//! ビットフィールド２
	u32 BitField2;
	//! ビットフィールド３
	u32 BitField3;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketScriptFlag()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketScriptFlag(u32 InBitField1, u32 InBitField2, u32 InBitField3)
	{
		BitField1 = InBitField1;
		BitField2 = InBitField2;
		BitField3 = InBitField3;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&BitField1);
		pStream->Serialize(&BitField2);
		pStream->Serialize(&BitField3);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSCRIPTFLAG_H__

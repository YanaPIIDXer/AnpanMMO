/**
 * @file PacketAddExp.h
 * @brief 経験値追加
 * @author NativePacketGenerator
 */

#ifndef __PACKETADDEXP_H__
#define __PACKETADDEXP_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 経験値追加
 */
class PacketAddExp  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::AddExp; }

	

	//! 経験値
	s32 Exp;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketAddExp()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketAddExp(s32 InExp)
	{
		Exp = InExp;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Exp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETADDEXP_H__

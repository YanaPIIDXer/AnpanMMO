/**
 * @file PacketTimeChange.h
 * @brief 時間変化通知パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETTIMECHANGE_H__
#define __PACKETTIMECHANGE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 時間変化通知パケット
 */
class PacketTimeChange  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::TimeChange; }

	

	//! マスタＩＤ
	u32 MasterId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketTimeChange()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketTimeChange(u32 InMasterId)
	{
		MasterId = InMasterId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MasterId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETTIMECHANGE_H__

/**
 * @file PacketTime.h
 * @brief ログイン時の時間通知
 * @author NativePacketGenerator
 */

#ifndef __PACKETTIME_H__
#define __PACKETTIME_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ログイン時の時間通知
 */
class PacketTime  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::Time; }

	

	//! マスタＩＤ
	u32 MasterId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketTime()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketTime(u32 InMasterId)
	{
		MasterId = InMasterId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MasterId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETTIME_H__

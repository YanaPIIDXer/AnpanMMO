/**
 * @file PacketExitPlayer.h
 * @brief プレイヤー退出
 * @author NativePacketGenerator
 */

#ifndef __PACKETEXITPLAYER_H__
#define __PACKETEXITPLAYER_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief プレイヤー退出
 */
class PacketExitPlayer  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::ExitPlayer; }

	

	//! 
u32 Uuid;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketExitPlayer()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketExitPlayer(u32 InUuid)
	{
		Uuid = InUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETEXITPLAYER_H__

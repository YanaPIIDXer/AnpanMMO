/**
 * @file PacketSpawnPlayer.h
 * @brief プレイヤー生成
 * @author NativePacketGenerator
 */

#ifndef __PACKETSPAWNPLAYER_H__
#define __PACKETSPAWNPLAYER_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PlayerData.h"
#include "PacketID.h"


/**
 * @brief プレイヤー生成
 */
class PacketSpawnPlayer  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SpawnPlayer; }

	

	//! プレイヤーデータ
	PlayerData Data;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSpawnPlayer()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSpawnPlayer(PlayerData InData)
	{
		Data = InData;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Data.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNPLAYER_H__

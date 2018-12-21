/**
 * @file PacketPlayerRespawn.h
 * @brief プレイヤーリスポン
 * @author NativePacketGenerator
 */

#ifndef __PACKETPLAYERRESPAWN_H__
#define __PACKETPLAYERRESPAWN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief プレイヤーリスポン
 */
class PacketPlayerRespawn  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PlayerRespawn; }

	

	//! 
u32 Uuid;
	//! 
float X;
	//! 
float Y;
	//! 
float Z;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPlayerRespawn()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPlayerRespawn(u32 InUuid, float InX, float InY, float InZ)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Z = InZ;
		
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
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPLAYERRESPAWN_H__

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
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PlayerRespawn; }

	

	//! UUID
	u32 Uuid;
	//! Ｘ座標
	float X;
	//! Ｙ座標
	float Y;
	//! Ｚ座標
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
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
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

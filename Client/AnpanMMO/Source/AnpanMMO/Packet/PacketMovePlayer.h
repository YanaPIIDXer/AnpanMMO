/**
 * @file PacketMovePlayer.h
 * @brief プレイヤー移動
 * @author NativePacketGenerator
 */

#ifndef __PACKETMOVEPLAYER_H__
#define __PACKETMOVEPLAYER_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief プレイヤー移動
 */
class PacketMovePlayer  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::MovePlayer; }

	

	//! UUID
	u32 Uuid;
	//! Ｘ座標
	float X;
	//! Ｙ座標
	float Y;
	//! Ｚ座標
	float Z;
	//! 回転
	float Rotation;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketMovePlayer()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketMovePlayer(u32 InUuid, float InX, float InY, float InZ, float InRotation)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Z = InZ;
		Rotation = InRotation;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		pStream->Serialize(&Rotation);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMOVEPLAYER_H__

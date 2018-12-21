/**
 * @file PacketMoveAnpan.h
 * @brief アンパン移動
 * @author NativePacketGenerator
 */

#ifndef __PACKETMOVEANPAN_H__
#define __PACKETMOVEANPAN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アンパン移動
 */
class PacketMoveAnpan  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::MoveAnpan; }

	

	//! 
u32 Uuid;
	//! 
float X;
	//! 
float Y;
	//! 
float Z;
	//! 
s32 MoveMilliSec;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketMoveAnpan()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketMoveAnpan(u32 InUuid, float InX, float InY, float InZ, s32 InMoveMilliSec)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Z = InZ;
		MoveMilliSec = InMoveMilliSec;
		
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
		pStream->Serialize(&MoveMilliSec);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMOVEANPAN_H__

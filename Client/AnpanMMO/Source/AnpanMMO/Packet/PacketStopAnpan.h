/**
 * @file PacketStopAnpan.h
 * @brief アンパン停止
 * @author NativePacketGenerator
 */

#ifndef __PACKETSTOPANPAN_H__
#define __PACKETSTOPANPAN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アンパン停止
 */
class PacketStopAnpan  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::StopAnpan; }

	

	//! 
u32 Uuid;
	//! 
float X;
	//! 
float Y;
	//! 
float Z;
	//! 
float Rotation;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketStopAnpan()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketStopAnpan(u32 InUuid, float InX, float InY, float InZ, float InRotation)
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
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
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

#endif		// #ifndef __PACKETSTOPANPAN_H__

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
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::StopAnpan; }

	

	//! UUID
	u32 Uuid;
	//! X座標
	float X;
	//! Y座標
	float Y;
	//! Z座標
	float Z;
	//! 回転
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
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
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

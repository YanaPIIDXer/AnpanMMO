/**
 * @file PacketRotateAnpan.h
 * @brief アンパン回転
 * @author NativePacketGenerator
 */

#ifndef __PACKETROTATEANPAN_H__
#define __PACKETROTATEANPAN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アンパン回転
 */
class PacketRotateAnpan  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::RotateAnpan; }

	

	//! UUID
	u32 Uuid;
	//! 回転
	float Rotation;
	//! 回転時間（ミリ秒）
	s32 RotateMilliSec;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketRotateAnpan()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketRotateAnpan(u32 InUuid, float InRotation, s32 InRotateMilliSec)
	{
		Uuid = InUuid;
		Rotation = InRotation;
		RotateMilliSec = InRotateMilliSec;
		
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
		pStream->Serialize(&Rotation);
		pStream->Serialize(&RotateMilliSec);
		
		return true;
	}
};

#endif		// #ifndef __PACKETROTATEANPAN_H__

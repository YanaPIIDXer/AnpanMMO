/**
 * @file AnpanData.h
 * @brief アンパンデータパケット
 * @author NativePacketGenerator
 */

#ifndef __ANPANDATA_H__
#define __ANPANDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief アンパンデータパケット
 */
class AnpanData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	

	

	//! UUID
	u32 Uuid;
	//! マスタＩＤ
	u32 MasterId;
	//! X座標
	float X;
	//! Y座標
	float Y;
	//! Z座標
	float Z;
	//! 回転
	float Rotation;
	//! HP
	s32 Hp;
	//! 最大HP
	s32 MaxHp;
	

	/**
	 * @brief コンストラクタ
	 */
	AnpanData()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	AnpanData(u32 InUuid, u32 InMasterId, float InX, float InY, float InZ, float InRotation, s32 InHp, s32 InMaxHp)
	{
		Uuid = InUuid;
		MasterId = InMasterId;
		X = InX;
		Y = InY;
		Z = InZ;
		Rotation = InRotation;
		Hp = InHp;
		MaxHp = InMaxHp;
		
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
		pStream->Serialize(&MasterId);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		pStream->Serialize(&Rotation);
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		
		return true;
	}
};

#endif		// #ifndef __ANPANDATA_H__

/**
 * @file PlayerData.h
 * @brief プレイヤーデータパケット
 * @author NativePacketGenerator
 */

#ifndef __PLAYERDATA_H__
#define __PLAYERDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief プレイヤーデータパケット
 */
class PlayerData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	

	

	//! ＵＵＩＤ
	u32 Uuid;
	//! Ｘ座標
	float X;
	//! Ｙ座標
	float Y;
	//! Ｚ座標
	float Z;
	//! 回転
	float Rotation;
	//! ＨＰ
	s32 Hp;
	//! 最大ＨＰ
	s32 MaxHp;
	//! 名前
	std::string Name;
	//! ジョブ
	u8 Job;
	

	/**
	 * @brief コンストラクタ
	 */
	PlayerData()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PlayerData(u32 InUuid, float InX, float InY, float InZ, float InRotation, s32 InHp, s32 InMaxHp, std::string InName, u8 InJob)
	{
		Uuid = InUuid;
		X = InX;
		Y = InY;
		Z = InZ;
		Rotation = InRotation;
		Hp = InHp;
		MaxHp = InMaxHp;
		Name = InName;
		Job = InJob;
		
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
		pStream->Serialize(&Hp);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Name);
		pStream->Serialize(&Job);
		
		return true;
	}
};

#endif		// #ifndef __PLAYERDATA_H__

/**
 * @file PacketAreaMove.h
 * @brief エリア移動
 * @author NativePacketGenerator
 */

#ifndef __PACKETAREAMOVE_H__
#define __PACKETAREAMOVE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief エリア移動
 */
class PacketAreaMove  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::AreaMove; }

	

	//! エリアＩＤ
	u32 AreaId;
	//! Ｘ座標
	float X;
	//! Ｙ座標
	float Y;
	//! Ｚ座標
	float Z;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketAreaMove()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketAreaMove(u32 InAreaId, float InX, float InY, float InZ)
	{
		AreaId = InAreaId;
		X = InX;
		Y = InY;
		Z = InZ;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaId);
		pStream->Serialize(&X);
		pStream->Serialize(&Y);
		pStream->Serialize(&Z);
		
		return true;
	}
};

#endif		// #ifndef __PACKETAREAMOVE_H__

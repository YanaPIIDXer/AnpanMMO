/**
 * @file PacketSpawnInstanceAreaExitPoint.h
 * @brief インスタンスマップ脱出ポイント生成
 * @author NativePacketGenerator
 */

#ifndef __PACKETSPAWNINSTANCEAREAEXITPOINT_H__
#define __PACKETSPAWNINSTANCEAREAEXITPOINT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief インスタンスマップ脱出ポイント生成
 */
class PacketSpawnInstanceAreaExitPoint  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SpawnInstanceAreaExitPoint; }

	

	//! ワープポイントＩＤ
	u32 WarpPointId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSpawnInstanceAreaExitPoint()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSpawnInstanceAreaExitPoint(u32 InWarpPointId)
	{
		WarpPointId = InWarpPointId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&WarpPointId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNINSTANCEAREAEXITPOINT_H__

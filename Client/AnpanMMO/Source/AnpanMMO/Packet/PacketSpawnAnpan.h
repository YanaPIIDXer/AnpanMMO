/**
 * @file PacketSpawnAnpan.h
 * @brief アンパン生成
 * @author NativePacketGenerator
 */

#ifndef __PACKETSPAWNANPAN_H__
#define __PACKETSPAWNANPAN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "AnpanData.h"
#include "PacketID.h"


/**
 * @brief アンパン生成
 */
class PacketSpawnAnpan  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SpawnAnpan; }

	

	//! 
AnpanData Data;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSpawnAnpan()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSpawnAnpan(AnpanData InData)
	{
		Data = InData;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Data.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNANPAN_H__

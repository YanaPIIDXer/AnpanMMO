/**
 * @file PacketPlayerList.h
 * @brief プレイヤーリストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPLAYERLIST_H__
#define __PACKETPLAYERLIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PlayerData.h"
#include "FlexArray.h"
#include "PacketID.h"


/**
 * @brief プレイヤーリストパケット
 */
class PacketPlayerList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PlayerList; }

	

	//! プレイヤーリスト
	FlexArray<PlayerData> List;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPlayerList()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPlayerList(FlexArray<PlayerData> InList)
	{
		List = InList;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		List.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPLAYERLIST_H__

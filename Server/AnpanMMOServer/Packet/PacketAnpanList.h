/**
 * @file PacketAnpanList.h
 * @brief アンパンリストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETANPANLIST_H__
#define __PACKETANPANLIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"
#include "AnpanData.h"
#include "PacketID.h"


/**
 * @brief アンパンリストパケット
 */
class PacketAnpanList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::AnpanList; }

	

	//! アンパンリスト
	FlexArray<AnpanData> List;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketAnpanList()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketAnpanList(FlexArray<AnpanData> InList)
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

#endif		// #ifndef __PACKETANPANLIST_H__

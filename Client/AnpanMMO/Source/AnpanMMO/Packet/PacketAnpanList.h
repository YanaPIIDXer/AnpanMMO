/**
 * @file PacketAnpanList.h
 * @brief アンパンリスト
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
 * @brief アンパンリスト
 */
class PacketAnpanList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::AnpanList; }

	

	//! 
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
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		List.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETANPANLIST_H__

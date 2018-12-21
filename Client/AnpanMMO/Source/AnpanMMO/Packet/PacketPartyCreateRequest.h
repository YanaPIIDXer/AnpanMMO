/**
 * @file PacketPartyCreateRequest.h
 * @brief パーティ作成リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYCREATEREQUEST_H__
#define __PACKETPARTYCREATEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ作成リクエスト
 */
class PacketPartyCreateRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyCreateRequest; }

	

	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyCreateRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYCREATEREQUEST_H__

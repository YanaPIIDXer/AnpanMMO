/**
 * @file PacketPartyDissolutionRequest.h
 * @brief パーティ解散リクエストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYDISSOLUTIONREQUEST_H__
#define __PACKETPARTYDISSOLUTIONREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ解散リクエストパケット
 */
class PacketPartyDissolutionRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyDissolutionRequest; }

	

	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyDissolutionRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYDISSOLUTIONREQUEST_H__

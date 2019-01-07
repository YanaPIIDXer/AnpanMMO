/**
 * @file PacketPartyInviteResponse.h
 * @brief パーティ勧誘レスポンスパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYINVITERESPONSE_H__
#define __PACKETPARTYINVITERESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ勧誘レスポンスパケット
 */
class PacketPartyInviteResponse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyInviteResponse; }

	enum ResponseCode
	{
		//! 
		Accept,
		//! 
		Refuse,
	};

	//! 
	u32 CustomerId;
	//! 
	u8 Response;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyInviteResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyInviteResponse(u32 InCustomerId, u8 InResponse)
	{
		CustomerId = InCustomerId;
		Response = InResponse;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&Response);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYINVITERESPONSE_H__

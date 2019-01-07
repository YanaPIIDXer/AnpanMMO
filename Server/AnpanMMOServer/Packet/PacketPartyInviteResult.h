/**
 * @file PacketPartyInviteResult.h
 * @brief パーティ勧誘結果パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYINVITERESULT_H__
#define __PACKETPARTYINVITERESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ勧誘結果パケット
 */
class PacketPartyInviteResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyInviteResult; }

	enum ResultCode
	{
		//! 
		Success,
		//! 
		AlreadyJoinOtherParty,
		//! 
		Error,
	};

	//! 
	u8 Result;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyInviteResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyInviteResult(u8 InResult)
	{
		Result = InResult;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYINVITERESULT_H__

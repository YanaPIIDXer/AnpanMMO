/**
 * @file PacketPartyInviteRequest.h
 * @brief パーティ勧誘リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYINVITEREQUEST_H__
#define __PACKETPARTYINVITEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ勧誘リクエスト
 */
class PacketPartyInviteRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyInviteRequest; }

	

	//! 
	u32 TargetUuid;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyInviteRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyInviteRequest(u32 InTargetUuid)
	{
		TargetUuid = InTargetUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TargetUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYINVITEREQUEST_H__

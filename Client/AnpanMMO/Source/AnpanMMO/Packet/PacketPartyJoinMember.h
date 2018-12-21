/**
 * @file PacketPartyJoinMember.h
 * @brief パーティメンバ加入
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYJOINMEMBER_H__
#define __PACKETPARTYJOINMEMBER_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PartyMemberData.h"
#include "PacketID.h"


/**
 * @brief パーティメンバ加入
 */
class PacketPartyJoinMember  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyJoinMember; }

	

	//! 
PartyMemberData MemberData;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyJoinMember()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyJoinMember(PartyMemberData InMemberData)
	{
		MemberData = InMemberData;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		MemberData.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYJOINMEMBER_H__

/**
 * @file PacketPartyJoin.h
 * @brief パーティ加入
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYJOIN_H__
#define __PACKETPARTYJOIN_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PartyMemberData.h"
#include "FlexArray.h"
#include "PacketID.h"


/**
 * @brief パーティ加入
 */
class PacketPartyJoin  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyJoin; }

	

	//! UUID
	u32 Uuid;
	//! メンバリスト
	FlexArray<PartyMemberData> MemberList;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyJoin()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyJoin(u32 InUuid, FlexArray<PartyMemberData> InMemberList)
	{
		Uuid = InUuid;
		MemberList = InMemberList;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		MemberList.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYJOIN_H__

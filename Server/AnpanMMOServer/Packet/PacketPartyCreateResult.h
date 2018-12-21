/**
 * @file PacketPartyCreateResult.h
 * @brief パーティ作成結果
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYCREATERESULT_H__
#define __PACKETPARTYCREATERESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ作成結果
 */
class PacketPartyCreateResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyCreateResult; }

	enum ResultCode
	{
		//! 
		Success,
		//! 
		AlreadyJoin,
		//! 
		Error,
	};

	//! 
	u8 Result;
	//! 
	u32 PartyId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyCreateResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyCreateResult(u8 InResult, u32 InPartyId)
	{
		Result = InResult;
		PartyId = InPartyId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&PartyId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYCREATERESULT_H__

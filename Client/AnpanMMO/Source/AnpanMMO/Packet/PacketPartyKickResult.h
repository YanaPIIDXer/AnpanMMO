/**
 * @file PacketPartyKickResult.h
 * @brief パーティメンバキック結果
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYKICKRESULT_H__
#define __PACKETPARTYKICKRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティメンバキック結果
 */
class PacketPartyKickResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyKickResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! 結果
	u8 Result;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyKickResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyKickResult(u8 InResult)
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

#endif		// #ifndef __PACKETPARTYKICKRESULT_H__

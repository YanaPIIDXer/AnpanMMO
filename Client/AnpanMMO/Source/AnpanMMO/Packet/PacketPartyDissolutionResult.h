/**
 * @file PacketPartyDissolutionResult.h
 * @brief パーティ解散結果
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYDISSOLUTIONRESULT_H__
#define __PACKETPARTYDISSOLUTIONRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ解散結果
 */
class PacketPartyDissolutionResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyDissolutionResult; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyDissolutionResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyDissolutionResult(u8 InResult)
	{
		Result = InResult;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYDISSOLUTIONRESULT_H__

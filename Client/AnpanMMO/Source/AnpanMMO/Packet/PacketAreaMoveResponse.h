/**
 * @file PacketAreaMoveResponse.h
 * @brief エリア移動レスポンス
 * @author NativePacketGenerator
 */

#ifndef __PACKETAREAMOVERESPONSE_H__
#define __PACKETAREAMOVERESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief エリア移動レスポンス
 */
class PacketAreaMoveResponse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::AreaMoveResponse; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		Fatal = エラー,
	};

	//! 
u8 Result;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketAreaMoveResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketAreaMoveResponse(u8 InResult)
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

#endif		// #ifndef __PACKETAREAMOVERESPONSE_H__

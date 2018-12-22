/**
 * @file PacketAreaMoveRequest.h
 * @brief エリア移動リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETAREAMOVEREQUEST_H__
#define __PACKETAREAMOVEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief エリア移動リクエスト
 */
class PacketAreaMoveRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::AreaMoveRequest; }

	

	//! エリアＩＤ
	u32 AreaMoveId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketAreaMoveRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketAreaMoveRequest(u32 InAreaMoveId)
	{
		AreaMoveId = InAreaMoveId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaMoveId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETAREAMOVEREQUEST_H__

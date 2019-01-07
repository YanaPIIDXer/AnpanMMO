/**
 * @file PacketCreateCharacterRequest.h
 * @brief キャラクタ作成リクエストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETCREATECHARACTERREQUEST_H__
#define __PACKETCREATECHARACTERREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief キャラクタ作成リクエストパケット
 */
class PacketCreateCharacterRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::CreateCharacterRequest; }

	

	//! キャラクタ名
	std::string CharacterName;
	//! ジョブ
	u8 Job;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketCreateCharacterRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketCreateCharacterRequest(std::string InCharacterName, u8 InJob)
	{
		CharacterName = InCharacterName;
		Job = InJob;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CharacterName);
		pStream->Serialize(&Job);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCREATECHARACTERREQUEST_H__

/**
 * @file CachePacketCreateCharacterRequest.h
 * @brief キャラクタ作成リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCREATECHARACTERREQUEST_H__
#define __CACHEPACKETCREATECHARACTERREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief キャラクタ作成リクエスト
 */
class CachePacketCreateCharacterRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCreateCharacterRequest; }

	

	//! カスタマID
	u32 CustomerId;
	//! キャラクタ名
	std::string CharacterName;
	//! ジョブ
	u8 Job;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketCreateCharacterRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketCreateCharacterRequest(u32 InClientId, u32 InCustomerId, std::string InCharacterName, u8 InJob)
	{
		ClientId = InClientId;
		CustomerId = InCustomerId;
		CharacterName = InCharacterName;
		Job = InJob;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&CharacterName);
		pStream->Serialize(&Job);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCREATECHARACTERREQUEST_H__

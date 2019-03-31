/**
 * @file CachePacketMailListResponse.h
 * @brief メールリストレスポンスパケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETMAILLISTRESPONSE_H__
#define __CACHEPACKETMAILLISTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "FlexArray.h"
#include "MailData.h"
#include "CacheServerPacketID.h"


/**
 * @brief メールリストレスポンスパケット
 */
class CachePacketMailListResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheMailListResponse; }

	

	//! メールリスト
	FlexArray<MailData> List;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketMailListResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketMailListResponse(u32 InClientId, FlexArray<MailData> InList)
	{
		ClientId = InClientId;
		List = InList;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		List.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETMAILLISTRESPONSE_H__

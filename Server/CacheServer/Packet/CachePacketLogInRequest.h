/**
 * @file CachePacketLogInRequest.h
 * @brief ログインリクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETLOGINREQUEST_H__
#define __CACHEPACKETLOGINREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ログインリクエスト
 */
class CachePacketLogInRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheLogInRequest; }

	

	//! ユーザコード
	std::string UserCode;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketLogInRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketLogInRequest(u32 InClientId, std::string InUserCode)
	{
		ClientId = InClientId;
		UserCode = InUserCode;
		
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
		pStream->Serialize(&UserCode);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGINREQUEST_H__

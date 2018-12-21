/**
 * @file PacketLogInRequest.h
 * @brief ログインリクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETLOGINREQUEST_H__
#define __PACKETLOGINREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ログインリクエスト
 */
class PacketLogInRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::LogInRequest; }

	

	//! ユーザコード
	std::string UserCode;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketLogInRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketLogInRequest(std::string InUserCode)
	{
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
		pStream->Serialize(&UserCode);
		
		return true;
	}
};

#endif		// #ifndef __PACKETLOGINREQUEST_H__

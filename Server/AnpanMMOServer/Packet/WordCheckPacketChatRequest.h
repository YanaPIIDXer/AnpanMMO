/**
 * @file WordCheckPacketChatRequest.h
 * @brief ワードチェック要求
 * @author NativePacketGenerator
 */

#ifndef __WORDCHECKPACKETCHATREQUEST_H__
#define __WORDCHECKPACKETCHATREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "WordCheckServerPacketID.h"


/**
 * @brief ワードチェック要求
 */
class WordCheckPacketChatRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return WordCheckPacketID::WordCheckChatRequest; }

	

	//! 
u8 Type;
	//! 
std::string Message;
	

	/**
	 * @brief コンストラクタ
	 */
	WordCheckPacketChatRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	WordCheckPacketChatRequest(u32 InClientId, u8 InType, std::string InMessage)
	{
		ClientId = InClientId;
		Type = InType;
		Message = InMessage;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Type);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __WORDCHECKPACKETCHATREQUEST_H__

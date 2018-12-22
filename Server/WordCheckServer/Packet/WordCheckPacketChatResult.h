/**
 * @file WordCheckPacketChatResult.h
 * @brief ワードチェック結果
 * @author NativePacketGenerator
 */

#ifndef __WORDCHECKPACKETCHATRESULT_H__
#define __WORDCHECKPACKETCHATRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "WordCheckServerPacketID.h"


/**
 * @brief ワードチェック結果
 */
class WordCheckPacketChatResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return WordCheckPacketID::WordCheckChatResult; }

	

	//! タイプ
	u8 Type;
	//! メッセージ
	std::string Message;
	

	/**
	 * @brief コンストラクタ
	 */
	WordCheckPacketChatResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	WordCheckPacketChatResult(u32 InClientId, u8 InType, std::string InMessage)
	{
		ClientId = InClientId;
		Type = InType;
		Message = InMessage;
		
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
		pStream->Serialize(&Type);
		pStream->Serialize(&Message);
		
		return true;
	}
};

#endif		// #ifndef __WORDCHECKPACKETCHATRESULT_H__

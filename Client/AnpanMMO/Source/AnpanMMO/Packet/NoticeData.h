/**
 * @file NoticeData.h
 * @brief 通知データパケット
 * @author NativePacketGenerator
 */

#ifndef __NOTICEDATA_H__
#define __NOTICEDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief 通知データパケット
 */
class NoticeData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	

	enum NoticeType
	{
		//! パーティ勧誘
		PartyInvide,
	};

	//! タイプ
	u8 Type;
	//! カスタマＩＤ
	u32 CustomerId;
	//! キャラクタ名
	std::string CharacterName;
	

	/**
	 * @brief コンストラクタ
	 */
	NoticeData()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	NoticeData(u8 InType, u32 InCustomerId, std::string InCharacterName)
	{
		Type = InType;
		CustomerId = InCustomerId;
		CharacterName = InCharacterName;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Type);
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&CharacterName);
		
		return true;
	}
};

#endif		// #ifndef __NOTICEDATA_H__

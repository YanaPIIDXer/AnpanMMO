/**
 * @file MailData.h
 * @brief メールデータパケット
 * @author NativePacketGenerator
 */

#ifndef __MAILDATA_H__
#define __MAILDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief メールデータパケット
 */
class MailData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	

	enum AttachmentKind
	{
		//! 無し
		None,
		//! アイテム
		Item,
		//! ゴールド
		Gold,
	};enum MailFlag
	{
		//! 未読
		NotRead,
		//! 既読
		Read,
		//! 添付物受注済み
		RecvAttachment,
	};

	//! ＩＤ
	u32 Id;
	//! 件名
	std::string Subject;
	//! 本文
	std::string Body;
	//! 添付物タイプ
	u8 AttachmentType;
	//! 添付物ＩＤ
	u32 AttachmentId;
	//! 添付物数
	u32 AttachmentCount;
	//! フラグ
	u8 Flag;
	

	/**
	 * @brief コンストラクタ
	 */
	MailData()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	MailData(u32 InId, std::string InSubject, std::string InBody, u8 InAttachmentType, u32 InAttachmentId, u32 InAttachmentCount, u8 InFlag)
	{
		Id = InId;
		Subject = InSubject;
		Body = InBody;
		AttachmentType = InAttachmentType;
		AttachmentId = InAttachmentId;
		AttachmentCount = InAttachmentCount;
		Flag = InFlag;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Id);
		pStream->Serialize(&Subject);
		pStream->Serialize(&Body);
		pStream->Serialize(&AttachmentType);
		pStream->Serialize(&AttachmentId);
		pStream->Serialize(&AttachmentCount);
		pStream->Serialize(&Flag);
		
		return true;
	}
};

#endif		// #ifndef __MAILDATA_H__

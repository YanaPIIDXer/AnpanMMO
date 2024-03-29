/**
 * @file PacketMailAttachmentRecvResult.h
 * @brief 添付物受信結果パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILATTACHMENTRECVRESULT_H__
#define __PACKETMAILATTACHMENTRECVRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 添付物受信結果パケット
 */
class PacketMailAttachmentRecvResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::MailAttachmentRecvResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! 受信済み
		AlreadyRecv,
		//! エラー
		Error,
	};

	//! ＩＤ
	u32 Id;
	//! リザルトコード
	u8 Result;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketMailAttachmentRecvResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketMailAttachmentRecvResult(u32 InId, u8 InResult)
	{
		Id = InId;
		Result = InResult;
		
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
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMAILATTACHMENTRECVRESULT_H__

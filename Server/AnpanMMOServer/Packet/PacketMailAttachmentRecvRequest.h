/**
 * @file PacketMailAttachmentRecvRequest.h
 * @brief 添付物受信リクエストパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILATTACHMENTRECVREQUEST_H__
#define __PACKETMAILATTACHMENTRECVREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 添付物受信リクエストパケット
 */
class PacketMailAttachmentRecvRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::MailAttachmentRecvRequest; }

	

	//! ＩＤ
	u32 Id;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketMailAttachmentRecvRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketMailAttachmentRecvRequest(u32 InId)
	{
		Id = InId;
		
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
		
		return true;
	}
};

#endif		// #ifndef __PACKETMAILATTACHMENTRECVREQUEST_H__

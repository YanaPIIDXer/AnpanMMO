/**
 * @file PacketMailAttachmentRecv.h
 * @brief 添付物受信パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILATTACHMENTRECV_H__
#define __PACKETMAILATTACHMENTRECV_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 添付物受信パケット
 */
class PacketMailAttachmentRecv  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::MailAttachmentRecv; }

	

	//! ＩＤ
	u32 Id;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketMailAttachmentRecv()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketMailAttachmentRecv(u32 InId)
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

#endif		// #ifndef __PACKETMAILATTACHMENTRECV_H__

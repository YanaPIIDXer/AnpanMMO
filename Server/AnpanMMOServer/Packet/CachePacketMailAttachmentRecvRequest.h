/**
 * @file CachePacketMailAttachmentRecvRequest.h
 * @brief メール添付物受信要求パケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETMAILATTACHMENTRECVREQUEST_H__
#define __CACHEPACKETMAILATTACHMENTRECVREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief メール添付物受信要求パケット
 */
class CachePacketMailAttachmentRecvRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheMailAttachmentRecvRequest; }

	

	//! ＩＤ
	u32 Id;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketMailAttachmentRecvRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketMailAttachmentRecvRequest(u32 InClientId, u32 InId)
	{
		ClientId = InClientId;
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
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Id);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETMAILATTACHMENTRECVREQUEST_H__

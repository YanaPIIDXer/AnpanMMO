/**
 * @file CachePacketMailAttachmentRecvResult.h
 * @brief メール添付物受信結果パケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETMAILATTACHMENTRECVRESULT_H__
#define __CACHEPACKETMAILATTACHMENTRECVRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief メール添付物受信結果パケット
 */
class CachePacketMailAttachmentRecvResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheMailAttachmentRecvResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! 結果コード
	u8 Result;
	//! 種類
	u8 Type;
	//! ＩＤ
	u32 Id;
	//! 数量
	u32 Count;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketMailAttachmentRecvResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketMailAttachmentRecvResult(u32 InClientId, u8 InResult, u8 InType, u32 InId, u32 InCount)
	{
		ClientId = InClientId;
		Result = InResult;
		Type = InType;
		Id = InId;
		Count = InCount;
		
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
		pStream->Serialize(&Result);
		pStream->Serialize(&Type);
		pStream->Serialize(&Id);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETMAILATTACHMENTRECVRESULT_H__

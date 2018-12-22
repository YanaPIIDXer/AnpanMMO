/**
 * @file CachePacketScriptFlagResponse.h
 * @brief スクリプトフラグレスポンス
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSCRIPTFLAGRESPONSE_H__
#define __CACHEPACKETSCRIPTFLAGRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief スクリプトフラグレスポンス
 */
class CachePacketScriptFlagResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheScriptFlagResponse; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! 結果
	u8 Result;
	//! ビットフィールド１
	u32 BitField1;
	//! ビットフィールド２
	u32 BitField2;
	//! ビットフィールド３
	u32 BitField3;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketScriptFlagResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketScriptFlagResponse(u32 InClientId, u8 InResult, u32 InBitField1, u32 InBitField2, u32 InBitField3)
	{
		ClientId = InClientId;
		Result = InResult;
		BitField1 = InBitField1;
		BitField2 = InBitField2;
		BitField3 = InBitField3;
		
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
		pStream->Serialize(&BitField1);
		pStream->Serialize(&BitField2);
		pStream->Serialize(&BitField3);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSCRIPTFLAGRESPONSE_H__

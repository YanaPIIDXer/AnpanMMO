/**
 * @file CachePacketCreateCharacterResult.h
 * @brief キャラクタ作成結果
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCREATECHARACTERRESULT_H__
#define __CACHEPACKETCREATECHARACTERRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief キャラクタ作成結果
 */
class CachePacketCreateCharacterResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCreateCharacterResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! 結果
	u8 Result;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketCreateCharacterResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketCreateCharacterResult(u32 InClientId, u8 InResult)
	{
		ClientId = InClientId;
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
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCREATECHARACTERRESULT_H__

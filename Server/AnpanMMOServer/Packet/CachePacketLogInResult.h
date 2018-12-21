/**
 * @file CachePacketLogInResult.h
 * @brief ログインリクエスト結果
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETLOGINRESULT_H__
#define __CACHEPACKETLOGINRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ログインリクエスト結果
 */
class CachePacketLogInResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheLogInResult; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		NoCharacter = キャラクタがいない,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	//! 
s32 CustomerId;
	//! 
u32 LastAreaId;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketLogInResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketLogInResult(u32 InClientId, u8 InResult, s32 InCustomerId, u32 InLastAreaId)
	{
		ClientId = InClientId;
		Result = InResult;
		CustomerId = InCustomerId;
		LastAreaId = InLastAreaId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&LastAreaId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGINRESULT_H__

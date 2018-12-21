/**
 * @file PacketLogInResult.h
 * @brief ログインリクエスト結果
 * @author NativePacketGenerator
 */

#ifndef __PACKETLOGINRESULT_H__
#define __PACKETLOGINRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ログインリクエスト結果
 */
class PacketLogInResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::LogInResult; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		DoubleLogIn = ダブルログイン,
		//! 
		NoCharacter = キャラクタが存在しない,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	//! 
s32 Uuid;
	//! 
u32 LastAreaId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketLogInResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketLogInResult(u8 InResult, s32 InUuid, u32 InLastAreaId)
	{
		Result = InResult;
		Uuid = InUuid;
		LastAreaId = InLastAreaId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&Uuid);
		pStream->Serialize(&LastAreaId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETLOGINRESULT_H__

/**
 * @file PacketLogInResult.h
 * @brief ログインリクエスト結果パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETLOGINRESULT_H__
#define __PACKETLOGINRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ログインリクエスト結果パケット
 */
class PacketLogInResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::LogInResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! ダブルログイン
		DoubleLogIn,
		//! キャラクタが存在しない
		NoCharacter,
		//! ＢＡＮされている
		Bunned,
		//! エラー
		Error,
	};

	//! 結果
	u8 Result;
	//! UUID
	s32 Uuid;
	//! 最終ログアウトエリアＩＤ
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
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
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

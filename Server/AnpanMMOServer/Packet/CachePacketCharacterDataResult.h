/**
 * @file CachePacketCharacterDataResult.h
 * @brief キャラクタ情報レスポンスパケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCHARACTERDATARESULT_H__
#define __CACHEPACKETCHARACTERDATARESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief キャラクタ情報レスポンスパケット
 */
class CachePacketCharacterDataResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCharacterDataResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! キャラクタＩＤ
	u32 CharacterId;
	//! 結果
	u8 Result;
	//! 名前
	std::string Name;
	//! ジョブ
	u8 Job;
	//! レベル
	u32 Level;
	//! 経験値
	s32 Exp;
	//! ゴールド
	u32 Gold;
	//! 右手装備
	u32 RightEquip;
	//! 左手装備
	u32 LeftEquip;
	//! ＧＭか？
	u8 IsGM;
	//! 最終ログアウトエリアＩＤ
	u32 LastAreaId;
	//! 最終ログアウトＸ座標
	float LastX;
	//! 最終ログアウトＹ座標
	float LastY;
	//! 最終ログアウトＺ座標
	float LastZ;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketCharacterDataResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketCharacterDataResult(u32 InClientId, u32 InCharacterId, u8 InResult, std::string InName, u8 InJob, u32 InLevel, s32 InExp, u32 InGold, u32 InRightEquip, u32 InLeftEquip, u8 InIsGM, u32 InLastAreaId, float InLastX, float InLastY, float InLastZ)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		Result = InResult;
		Name = InName;
		Job = InJob;
		Level = InLevel;
		Exp = InExp;
		Gold = InGold;
		RightEquip = InRightEquip;
		LeftEquip = InLeftEquip;
		IsGM = InIsGM;
		LastAreaId = InLastAreaId;
		LastX = InLastX;
		LastY = InLastY;
		LastZ = InLastZ;
		
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
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&Result);
		pStream->Serialize(&Name);
		pStream->Serialize(&Job);
		pStream->Serialize(&Level);
		pStream->Serialize(&Exp);
		pStream->Serialize(&Gold);
		pStream->Serialize(&RightEquip);
		pStream->Serialize(&LeftEquip);
		pStream->Serialize(&IsGM);
		pStream->Serialize(&LastAreaId);
		pStream->Serialize(&LastX);
		pStream->Serialize(&LastY);
		pStream->Serialize(&LastZ);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHARACTERDATARESULT_H__

/**
 * @file CachePacketCharacterDataSave.h
 * @brief キャラクタ保存リクエストパケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCHARACTERDATASAVE_H__
#define __CACHEPACKETCHARACTERDATASAVE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief キャラクタ保存リクエストパケット
 */
class CachePacketCharacterDataSave  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCharacterDataSave; }

	

	//! キャラクタＩＤ
	u32 CharacterId;
	//! レベル
	u32 Level;
	//! 最大ＨＰ
	s32 MaxHp;
	//! 攻撃力
	s32 Atk;
	//! 防御力
	s32 Def;
	//! 経験値
	s32 Exp;
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
	CachePacketCharacterDataSave()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketCharacterDataSave(u32 InClientId, u32 InCharacterId, u32 InLevel, s32 InMaxHp, s32 InAtk, s32 InDef, s32 InExp, u32 InLastAreaId, float InLastX, float InLastY, float InLastZ)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		Level = InLevel;
		MaxHp = InMaxHp;
		Atk = InAtk;
		Def = InDef;
		Exp = InExp;
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
		pStream->Serialize(&Level);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Atk);
		pStream->Serialize(&Def);
		pStream->Serialize(&Exp);
		pStream->Serialize(&LastAreaId);
		pStream->Serialize(&LastX);
		pStream->Serialize(&LastY);
		pStream->Serialize(&LastZ);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHARACTERDATASAVE_H__

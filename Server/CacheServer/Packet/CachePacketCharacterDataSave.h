/**
 * @file CachePacketCharacterDataSave.h
 * @brief キャラクタ保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCHARACTERDATASAVE_H__
#define __CACHEPACKETCHARACTERDATASAVE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief キャラクタ保存リクエスト
 */
class CachePacketCharacterDataSave  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCharacterDataSave; }

	

	//! 
u32 CharacterId;
	//! 
u32 Level;
	//! 
s32 MaxHp;
	//! 
s32 Atk;
	//! 
s32 Def;
	//! 
s32 Exp;
	//! 
u32 LastAreaId;
	//! 
float LastX;
	//! 
float LastY;
	//! 
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
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
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

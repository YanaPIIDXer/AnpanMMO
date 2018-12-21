/**
 * @file CachePacketCharacterDataResult.h
 * @brief キャラクタ情報レスポンス
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCHARACTERDATARESULT_H__
#define __CACHEPACKETCHARACTERDATARESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief キャラクタ情報レスポンス
 */
class CachePacketCharacterDataResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCharacterDataResult; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		Error = エラー,
	};

	//! 
u32 CharacterId;
	//! 
u8 Result;
	//! 
std::string Name;
	//! 
u8 Job;
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
u32 Gold;
	//! 
u32 LastAreaId;
	//! 
float LastX;
	//! 
float LastY;
	//! 
float LastZ;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketCharacterDataResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketCharacterDataResult(u32 InClientId, u32 InCharacterId, u8 InResult, std::string InName, u8 InJob, u32 InLevel, s32 InMaxHp, s32 InAtk, s32 InDef, s32 InExp, u32 InGold, u32 InLastAreaId, float InLastX, float InLastY, float InLastZ)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		Result = InResult;
		Name = InName;
		Job = InJob;
		Level = InLevel;
		MaxHp = InMaxHp;
		Atk = InAtk;
		Def = InDef;
		Exp = InExp;
		Gold = InGold;
		LastAreaId = InLastAreaId;
		LastX = InLastX;
		LastY = InLastY;
		LastZ = InLastZ;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&Result);
		pStream->Serialize(&Name);
		pStream->Serialize(&Job);
		pStream->Serialize(&Level);
		pStream->Serialize(&MaxHp);
		pStream->Serialize(&Atk);
		pStream->Serialize(&Def);
		pStream->Serialize(&Exp);
		pStream->Serialize(&Gold);
		pStream->Serialize(&LastAreaId);
		pStream->Serialize(&LastX);
		pStream->Serialize(&LastY);
		pStream->Serialize(&LastZ);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHARACTERDATARESULT_H__

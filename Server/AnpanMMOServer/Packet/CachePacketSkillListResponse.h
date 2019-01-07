/**
 * @file CachePacketSkillListResponse.h
 * @brief スキルリストレスポンスパケット
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSKILLLISTRESPONSE_H__
#define __CACHEPACKETSKILLLISTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief スキルリストレスポンスパケット
 */
class CachePacketSkillListResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSkillListResponse; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! 結果
	u8 Result;
	//! 通常攻撃ＩＤ
	u32 NormalAttackId;
	//! スキルＩＤ１
	u32 SkillId1;
	//! スキルＩＤ２
	u32 SkillId2;
	//! スキルＩＤ３
	u32 SkillId3;
	//! スキルＩＤ４
	u32 SkillId4;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSkillListResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSkillListResponse(u32 InClientId, u8 InResult, u32 InNormalAttackId, u32 InSkillId1, u32 InSkillId2, u32 InSkillId3, u32 InSkillId4)
	{
		ClientId = InClientId;
		Result = InResult;
		NormalAttackId = InNormalAttackId;
		SkillId1 = InSkillId1;
		SkillId2 = InSkillId2;
		SkillId3 = InSkillId3;
		SkillId4 = InSkillId4;
		
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
		pStream->Serialize(&NormalAttackId);
		pStream->Serialize(&SkillId1);
		pStream->Serialize(&SkillId2);
		pStream->Serialize(&SkillId3);
		pStream->Serialize(&SkillId4);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSKILLLISTRESPONSE_H__

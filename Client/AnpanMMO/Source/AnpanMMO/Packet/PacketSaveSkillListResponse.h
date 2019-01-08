/**
 * @file PacketSaveSkillListResponse.h
 * @brief スキルリスト保存レスポンスパケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETSAVESKILLLISTRESPONSE_H__
#define __PACKETSAVESKILLLISTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキルリスト保存レスポンスパケット
 */
class PacketSaveSkillListResponse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SaveSkillListResponse; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! エラー
		Error,
	};

	//! 結果
	u8 Result;
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
	PacketSaveSkillListResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSaveSkillListResponse(u8 InResult, u32 InSkillId1, u32 InSkillId2, u32 InSkillId3, u32 InSkillId4)
	{
		Result = InResult;
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
		pStream->Serialize(&Result);
		pStream->Serialize(&SkillId1);
		pStream->Serialize(&SkillId2);
		pStream->Serialize(&SkillId3);
		pStream->Serialize(&SkillId4);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVESKILLLISTRESPONSE_H__

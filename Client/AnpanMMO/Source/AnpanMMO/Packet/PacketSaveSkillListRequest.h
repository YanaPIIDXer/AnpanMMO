/**
 * @file PacketSaveSkillListRequest.h
 * @brief スキルリスト保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETSAVESKILLLISTREQUEST_H__
#define __PACKETSAVESKILLLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキルリスト保存リクエスト
 */
class PacketSaveSkillListRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SaveSkillListRequest; }

	

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
	PacketSaveSkillListRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSaveSkillListRequest(u32 InSkillId1, u32 InSkillId2, u32 InSkillId3, u32 InSkillId4)
	{
		SkillId1 = InSkillId1;
		SkillId2 = InSkillId2;
		SkillId3 = InSkillId3;
		SkillId4 = InSkillId4;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId1);
		pStream->Serialize(&SkillId2);
		pStream->Serialize(&SkillId3);
		pStream->Serialize(&SkillId4);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVESKILLLISTREQUEST_H__

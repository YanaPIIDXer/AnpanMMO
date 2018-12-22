/**
 * @file PacketSkillActivate.h
 * @brief スキル発動
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLACTIVATE_H__
#define __PACKETSKILLACTIVATE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキル発動
 */
class PacketSkillActivate  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillActivate; }

	

	//! キャラクタタイプ
	u8 CharacterType;
	//! キャラクタＵＵＩＤ
	u32 CharacterUuid;
	//! スキルＩＤ
	u32 SkillId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillActivate()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillActivate(u8 InCharacterType, u32 InCharacterUuid, u32 InSkillId)
	{
		CharacterType = InCharacterType;
		CharacterUuid = InCharacterUuid;
		SkillId = InSkillId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CharacterType);
		pStream->Serialize(&CharacterUuid);
		pStream->Serialize(&SkillId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLACTIVATE_H__

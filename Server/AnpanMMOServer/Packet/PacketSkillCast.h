/**
 * @file PacketSkillCast.h
 * @brief スキル詠唱開始
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLCAST_H__
#define __PACKETSKILLCAST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキル詠唱開始
 */
class PacketSkillCast  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillCast; }

	

	//! スキルＩＤ
	u32 SkillId;
	//! キャラクタタイプ
	u8 CharacterType;
	//! キャラクタＵＵＩＤ
	u32 CharacterUuid;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillCast()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillCast(u32 InSkillId, u8 InCharacterType, u32 InCharacterUuid)
	{
		SkillId = InSkillId;
		CharacterType = InCharacterType;
		CharacterUuid = InCharacterUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId);
		pStream->Serialize(&CharacterType);
		pStream->Serialize(&CharacterUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLCAST_H__

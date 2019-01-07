/**
 * @file PacketSkillCastFinish.h
 * @brief スキル詠唱完了パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLCASTFINISH_H__
#define __PACKETSKILLCASTFINISH_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキル詠唱完了パケット
 */
class PacketSkillCastFinish  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillCastFinish; }

	

	//! キャラクタタイプ
	u8 CharacterType;
	//! キャラクタＵＵＩＤ
	u32 CharacterUuid;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillCastFinish()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillCastFinish(u8 InCharacterType, u32 InCharacterUuid)
	{
		CharacterType = InCharacterType;
		CharacterUuid = InCharacterUuid;
		
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
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLCASTFINISH_H__

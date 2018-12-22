/**
 * @file PacketSkillRecast.h
 * @brief リキャスト完了
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLRECAST_H__
#define __PACKETSKILLRECAST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief リキャスト完了
 */
class PacketSkillRecast  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillRecast; }

	

	//! スキルＩＤ
	u32 SkillId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillRecast()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillRecast(u32 InSkillId)
	{
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
		pStream->Serialize(&SkillId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLRECAST_H__

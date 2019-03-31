/**
 * @file PartyMemberData.h
 * @brief パーティメンバ情報パケット
 * @author NativePacketGenerator
 */

#ifndef __PARTYMEMBERDATA_H__
#define __PARTYMEMBERDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief パーティメンバ情報パケット
 */
class PartyMemberData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	

	

	//! UUID
	u32 Uuid;
	//! キャラクタ名
	std::string CharacterName;
	

	/**
	 * @brief コンストラクタ
	 */
	PartyMemberData()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PartyMemberData(u32 InUuid, std::string InCharacterName)
	{
		Uuid = InUuid;
		CharacterName = InCharacterName;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		pStream->Serialize(&CharacterName);
		
		return true;
	}
};

#endif		// #ifndef __PARTYMEMBERDATA_H__

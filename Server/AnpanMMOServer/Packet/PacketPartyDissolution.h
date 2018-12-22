/**
 * @file PacketPartyDissolution.h
 * @brief パーティ解散
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYDISSOLUTION_H__
#define __PACKETPARTYDISSOLUTION_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ解散
 */
class PacketPartyDissolution  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyDissolution; }

	

	

	/**
	 * @brief コンストラクタ
	 */
	PacketPartyDissolution()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYDISSOLUTION_H__

/**
 * @file PacketSpawnPlayer.h
 * @brief プレイヤー生成
 * @author NativePacketGenerator
 */

#ifndef __PACKETSPAWNPLAYER_H__
#define __PACKETSPAWNPLAYER_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PlayerData.h"
#include "PacketID.h"


/**
 * @brief プレイヤー生成
 */
class PacketSpawnPlayer  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SpawnPlayer; }

	

	//! 
PlayerData Data;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSpawnPlayer()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSpawnPlayer(PlayerData InData)
	{
		Data = InData;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Data.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNPLAYER_H__

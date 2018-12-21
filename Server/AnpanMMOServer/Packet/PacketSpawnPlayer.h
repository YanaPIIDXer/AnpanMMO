/**
 * @file PacketSpawnPlayer.h
 * @brief �v���C���[����
 * @author NativePacketGenerator
 */

#ifndef __PACKETSPAWNPLAYER_H__
#define __PACKETSPAWNPLAYER_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PlayerData.h"
#include "PacketID.h"


/**
 * @brief �v���C���[����
 */
class PacketSpawnPlayer  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SpawnPlayer; }

	

	//! �v���C���[�f�[�^
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
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Data.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSPAWNPLAYER_H__

/**
 * @file PacketExitPlayer.h
 * @brief �v���C���[�ޏo
 * @author NativePacketGenerator
 */

#ifndef __PACKETEXITPLAYER_H__
#define __PACKETEXITPLAYER_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �v���C���[�ޏo
 */
class PacketExitPlayer  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ExitPlayer; }

	

	//! UUID
	u32 Uuid;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketExitPlayer()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketExitPlayer(u32 InUuid)
	{
		Uuid = InUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Uuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETEXITPLAYER_H__

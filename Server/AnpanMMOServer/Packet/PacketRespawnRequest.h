/**
 * @file PacketRespawnRequest.h
 * @brief プレイヤーリスポン要求
 * @author NativePacketGenerator
 */

#ifndef __PACKETRESPAWNREQUEST_H__
#define __PACKETRESPAWNREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief プレイヤーリスポン要求
 */
class PacketRespawnRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::RespawnRequest; }

	

	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketRespawnRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETRESPAWNREQUEST_H__

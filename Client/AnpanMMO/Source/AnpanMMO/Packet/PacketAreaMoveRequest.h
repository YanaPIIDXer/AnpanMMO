/**
 * @file PacketAreaMoveRequest.h
 * @brief �G���A�ړ����N�G�X�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETAREAMOVEREQUEST_H__
#define __PACKETAREAMOVEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �G���A�ړ����N�G�X�g
 */
class PacketAreaMoveRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::AreaMoveRequest; }

	

	//! �G���A�h�c
	u32 AreaMoveId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAreaMoveRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAreaMoveRequest(u32 InAreaMoveId)
	{
		AreaMoveId = InAreaMoveId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaMoveId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETAREAMOVEREQUEST_H__

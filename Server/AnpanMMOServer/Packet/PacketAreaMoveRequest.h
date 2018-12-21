/**
 * @file PacketAreaMoveRequest.h
 * @brief エリア移動リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETAREAMOVEREQUEST_H__
#define __PACKETAREAMOVEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief エリア移動リクエスト
 */
class PacketAreaMoveRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::AreaMoveRequest; }

	

	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&AreaMoveId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETAREAMOVEREQUEST_H__

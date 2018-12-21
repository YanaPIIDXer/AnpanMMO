/**
 * @file PacketPartyCreateRequest.h
 * @brief パーティ作成リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYCREATEREQUEST_H__
#define __PACKETPARTYCREATEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ作成リクエスト
 */
class PacketPartyCreateRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyCreateRequest; }

	

	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyCreateRequest()
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

#endif		// #ifndef __PACKETPARTYCREATEREQUEST_H__

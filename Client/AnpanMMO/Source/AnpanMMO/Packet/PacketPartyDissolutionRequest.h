/**
 * @file PacketPartyDissolutionRequest.h
 * @brief パーティ解散リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYDISSOLUTIONREQUEST_H__
#define __PACKETPARTYDISSOLUTIONREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ解散リクエスト
 */
class PacketPartyDissolutionRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyDissolutionRequest; }

	

	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyDissolutionRequest()
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

#endif		// #ifndef __PACKETPARTYDISSOLUTIONREQUEST_H__

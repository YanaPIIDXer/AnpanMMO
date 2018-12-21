/**
 * @file PacketQuestRetireRequest.h
 * @brief クエスト破棄リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTRETIREREQUEST_H__
#define __PACKETQUESTRETIREREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief クエスト破棄リクエスト
 */
class PacketQuestRetireRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestRetireRequest; }

	

	//! 
u32 QuestId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestRetireRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestRetireRequest(u32 InQuestId)
	{
		QuestId = InQuestId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTRETIREREQUEST_H__

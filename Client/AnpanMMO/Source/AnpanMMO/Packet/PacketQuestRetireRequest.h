/**
 * @file PacketQuestRetireRequest.h
 * @brief �N�G�X�g�j�����N�G�X�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTRETIREREQUEST_H__
#define __PACKETQUESTRETIREREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �N�G�X�g�j�����N�G�X�g
 */
class PacketQuestRetireRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestRetireRequest; }

	

	//! �N�G�X�g�h�c
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
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTRETIREREQUEST_H__

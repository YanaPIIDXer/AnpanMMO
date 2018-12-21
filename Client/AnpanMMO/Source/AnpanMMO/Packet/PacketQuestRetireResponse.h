/**
 * @file PacketQuestRetireResponse.h
 * @brief �N�G�X�g�j�����X�|���X
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTRETIRERESPONSE_H__
#define __PACKETQUESTRETIRERESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �N�G�X�g�j�����X�|���X
 */
class PacketQuestRetireResponse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestRetireResponse; }

	enum ResultCode
	{
		//! ����
		Success,
		//! ���C���N�G�X�g
		MainQuest,
		//! �G���[
		Error,
	};

	//! �N�G�X�g�h�c
	u32 QuestId;
	//! ����
	u8 Result;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestRetireResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestRetireResponse(u32 InQuestId, u8 InResult)
	{
		QuestId = InQuestId;
		Result = InResult;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTRETIRERESPONSE_H__

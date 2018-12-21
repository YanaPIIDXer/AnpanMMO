/**
 * @file CachePacketQuestRetireRequest.h
 * @brief クエスト破棄リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETQUESTRETIREREQUEST_H__
#define __CACHEPACKETQUESTRETIREREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief クエスト破棄リクエスト
 */
class CachePacketQuestRetireRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheQuestRetireRequest; }

	

	//! 
u32 CharacterId;
	//! 
u32 QuestId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketQuestRetireRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketQuestRetireRequest(u32 InClientId, u32 InCharacterId, u32 InQuestId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
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
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETQUESTRETIREREQUEST_H__

/**
 * @file CachePacketSaveActiveQuestRequest.h
 * @brief アクティブクエスト保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVEACTIVEQUESTREQUEST_H__
#define __CACHEPACKETSAVEACTIVEQUESTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief アクティブクエスト保存リクエスト
 */
class CachePacketSaveActiveQuestRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveActiveQuestRequest; }

	

	//! 
u32 CharacterId;
	//! 
u32 QuestId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveActiveQuestRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveActiveQuestRequest(u32 InClientId, u32 InCharacterId, u32 InQuestId)
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

#endif		// #ifndef __CACHEPACKETSAVEACTIVEQUESTREQUEST_H__

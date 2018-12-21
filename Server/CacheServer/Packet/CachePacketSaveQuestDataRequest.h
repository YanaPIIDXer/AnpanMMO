/**
 * @file CachePacketSaveQuestDataRequest.h
 * @brief クエストデータ保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVEQUESTDATAREQUEST_H__
#define __CACHEPACKETSAVEQUESTDATAREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "QuestData.h"
#include "CacheServerPacketID.h"


/**
 * @brief クエストデータ保存リクエスト
 */
class CachePacketSaveQuestDataRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveQuestDataRequest; }

	

	//! 
u32 CharacterId;
	//! 
QuestData Data;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveQuestDataRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveQuestDataRequest(u32 InClientId, u32 InCharacterId, QuestData InData)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		Data = InData;
		
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
		Data.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEQUESTDATAREQUEST_H__

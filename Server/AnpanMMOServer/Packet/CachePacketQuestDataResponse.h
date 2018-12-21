/**
 * @file CachePacketQuestDataResponse.h
 * @brief クエストデータレスポンス
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETQUESTDATARESPONSE_H__
#define __CACHEPACKETQUESTDATARESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "FlexArray.h"
#include "QuestData.h"
#include "CacheServerPacketID.h"


/**
 * @brief クエストデータレスポンス
 */
class CachePacketQuestDataResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheQuestDataResponse; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	//! 
FlexArray<QuestData> Quests;
	//! 
u32 ActiveQuestId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketQuestDataResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketQuestDataResponse(u32 InClientId, u8 InResult, FlexArray<QuestData> InQuests, u32 InActiveQuestId)
	{
		ClientId = InClientId;
		Result = InResult;
		Quests = InQuests;
		ActiveQuestId = InActiveQuestId;
		
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
		pStream->Serialize(&Result);
		Quests.Serialize(pStream);
		pStream->Serialize(&ActiveQuestId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETQUESTDATARESPONSE_H__

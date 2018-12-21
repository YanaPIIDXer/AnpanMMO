/**
 * @file CachePacketQuestDataResponse.h
 * @brief �N�G�X�g�f�[�^���X�|���X
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
 * @brief �N�G�X�g�f�[�^���X�|���X
 */
class CachePacketQuestDataResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheQuestDataResponse; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Error,
	};

	//! ����
	u8 Result;
	//! �N�G�X�g���X�g
	FlexArray<QuestData> Quests;
	//! �A�N�e�B�u�N�G�X�g�h�c
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
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
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

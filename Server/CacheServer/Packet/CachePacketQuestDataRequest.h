/**
 * @file CachePacketQuestDataRequest.h
 * @brief クエストデータリクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETQUESTDATAREQUEST_H__
#define __CACHEPACKETQUESTDATAREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief クエストデータリクエスト
 */
class CachePacketQuestDataRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheQuestDataRequest; }

	

	//! 
u32 CharacterId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketQuestDataRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketQuestDataRequest(u32 InClientId, u32 InCharacterId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		
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
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETQUESTDATAREQUEST_H__

/**
 * @file PacketQuestData.h
 * @brief クエストデータリスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTDATA_H__
#define __PACKETQUESTDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"
#include "QuestData.h"
#include "PacketID.h"


/**
 * @brief クエストデータリスト
 */
class PacketQuestData  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestData; }

	

	//! 
FlexArray<QuestData> Quests;
	//! 
u32 ActiveQuestId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestData(FlexArray<QuestData> InQuests, u32 InActiveQuestId)
	{
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
		Quests.Serialize(pStream);
		pStream->Serialize(&ActiveQuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTDATA_H__

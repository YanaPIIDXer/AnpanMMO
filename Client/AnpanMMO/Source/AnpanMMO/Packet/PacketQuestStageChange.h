/**
 * @file PacketQuestStageChange.h
 * @brief クエストステージ進行
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTSTAGECHANGE_H__
#define __PACKETQUESTSTAGECHANGE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief クエストステージ進行
 */
class PacketQuestStageChange  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestStageChange; }

	

	//! 
u32 QuestId;
	//! 
u32 StageNo;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestStageChange()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestStageChange(u32 InQuestId, u32 InStageNo)
	{
		QuestId = InQuestId;
		StageNo = InStageNo;
		
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
		pStream->Serialize(&StageNo);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTSTAGECHANGE_H__

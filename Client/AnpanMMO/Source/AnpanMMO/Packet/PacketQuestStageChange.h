/**
 * @file PacketQuestStageChange.h
 * @brief �N�G�X�g�X�e�[�W�i�s
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTSTAGECHANGE_H__
#define __PACKETQUESTSTAGECHANGE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �N�G�X�g�X�e�[�W�i�s
 */
class PacketQuestStageChange  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestStageChange; }

	

	//! �N�G�X�g�h�c
	u32 QuestId;
	//! �X�e�[�W�ԍ�
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
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&QuestId);
		pStream->Serialize(&StageNo);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTSTAGECHANGE_H__

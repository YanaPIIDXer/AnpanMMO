/**
 * @file QuestData.h
 * @brief �N�G�X�g�f�[�^�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __QUESTDATA_H__
#define __QUESTDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief �N�G�X�g�f�[�^�p�P�b�g
 */
class QuestData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	enum StateType
	{
		//! �i�s��
		Active,
		//! �N���A�ς�
		Cleared,
	};

	//! �N�G�X�g�h�c
	u32 QuestId;
	//! �X�e�[�W�ԍ�
	u32 StageNo;
	//! �E�Q��
	u32 KillCount;
	//! �X�e�[�g
	u8 State;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	QuestData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	QuestData(u32 InQuestId, u32 InStageNo, u32 InKillCount, u8 InState)
	{
		QuestId = InQuestId;
		StageNo = InStageNo;
		KillCount = InKillCount;
		State = InState;
		
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
		pStream->Serialize(&KillCount);
		pStream->Serialize(&State);
		
		return true;
	}
};

#endif		// #ifndef __QUESTDATA_H__

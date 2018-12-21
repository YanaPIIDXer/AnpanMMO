/**
 * @file PacketSaveActiveQuest.h
 * @brief アクティブクエスト保存
 * @author NativePacketGenerator
 */

#ifndef __PACKETSAVEACTIVEQUEST_H__
#define __PACKETSAVEACTIVEQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アクティブクエスト保存
 */
class PacketSaveActiveQuest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SaveActiveQuest; }

	

	//! 
u32 QuestId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSaveActiveQuest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSaveActiveQuest(u32 InQuestId)
	{
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
		pStream->Serialize(&QuestId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVEACTIVEQUEST_H__

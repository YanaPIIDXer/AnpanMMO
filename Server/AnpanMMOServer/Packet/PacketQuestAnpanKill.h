/**
 * @file PacketQuestAnpanKill.h
 * @brief クエストアンパンキル
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTANPANKILL_H__
#define __PACKETQUESTANPANKILL_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief クエストアンパンキル
 */
class PacketQuestAnpanKill  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestAnpanKill; }

	

	//! 
u32 QuestId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestAnpanKill()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestAnpanKill(u32 InQuestId)
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

#endif		// #ifndef __PACKETQUESTANPANKILL_H__

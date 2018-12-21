/**
 * @file PacketQuestClear.h
 * @brief クエストクリア
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTCLEAR_H__
#define __PACKETQUESTCLEAR_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief クエストクリア
 */
class PacketQuestClear  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestClear; }

	

	//! 
u32 QuestId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestClear()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestClear(u32 InQuestId)
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

#endif		// #ifndef __PACKETQUESTCLEAR_H__

/**
 * @file PacketQuestRetireResponse.h
 * @brief クエスト破棄レスポンス
 * @author NativePacketGenerator
 */

#ifndef __PACKETQUESTRETIRERESPONSE_H__
#define __PACKETQUESTRETIRERESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief クエスト破棄レスポンス
 */
class PacketQuestRetireResponse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::QuestRetireResponse; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		MainQuest = メインクエスト,
		//! 
		Error = エラー,
	};

	//! 
u32 QuestId;
	//! 
u8 Result;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestRetireResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketQuestRetireResponse(u32 InQuestId, u8 InResult)
	{
		QuestId = InQuestId;
		Result = InResult;
		
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
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETQUESTRETIRERESPONSE_H__

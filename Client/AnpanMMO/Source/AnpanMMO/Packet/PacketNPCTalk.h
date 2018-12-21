/**
 * @file PacketNPCTalk.h
 * @brief 会話開始
 * @author NativePacketGenerator
 */

#ifndef __PACKETNPCTALK_H__
#define __PACKETNPCTALK_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 会話開始
 */
class PacketNPCTalk  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::NPCTalk; }

	

	//! 
u32 MasterId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketNPCTalk()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketNPCTalk(u32 InMasterId)
	{
		MasterId = InMasterId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MasterId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETNPCTALK_H__

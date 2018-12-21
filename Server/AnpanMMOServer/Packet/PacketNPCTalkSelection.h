/**
 * @file PacketNPCTalkSelection.h
 * @brief 選択肢を選択
 * @author NativePacketGenerator
 */

#ifndef __PACKETNPCTALKSELECTION_H__
#define __PACKETNPCTALKSELECTION_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 選択肢を選択
 */
class PacketNPCTalkSelection  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::NPCTalkSelection; }

	

	//! 
s32 Index;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketNPCTalkSelection()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketNPCTalkSelection(s32 InIndex)
	{
		Index = InIndex;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Index);
		
		return true;
	}
};

#endif		// #ifndef __PACKETNPCTALKSELECTION_H__

/**
 * @file PacketNPCTalk.h
 * @brief ��b�J�n
 * @author NativePacketGenerator
 */

#ifndef __PACKETNPCTALK_H__
#define __PACKETNPCTALK_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ��b�J�n
 */
class PacketNPCTalk  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::NPCTalk; }

	

	//! �m�o�b�}�X�^�h�c
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
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MasterId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETNPCTALK_H__

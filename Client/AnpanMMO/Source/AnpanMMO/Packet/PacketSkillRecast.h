/**
 * @file PacketSkillRecast.h
 * @brief ���L���X�g����
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLRECAST_H__
#define __PACKETSKILLRECAST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ���L���X�g����
 */
class PacketSkillRecast  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillRecast; }

	

	//! �X�L���h�c
	u32 SkillId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillRecast()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillRecast(u32 InSkillId)
	{
		SkillId = InSkillId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLRECAST_H__

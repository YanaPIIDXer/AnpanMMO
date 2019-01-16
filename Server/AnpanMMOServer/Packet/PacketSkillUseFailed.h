/**
 * @file PacketSkillUseFailed.h
 * @brief �X�L���g�p���s�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLUSEFAILED_H__
#define __PACKETSKILLUSEFAILED_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �X�L���g�p���s�p�P�b�g
 */
class PacketSkillUseFailed  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillUseFailed; }

	enum ReasonType
	{
		//! ���L���X�g��
		RecastTime,
		//! �����ȃX�L��
		InvalidSkill,
		//! ���
		Paralysis,
		//! �L�����Z��
		Cancel,
		//! �^�[�Q�b�g����
		TargetDisappeared,
	};

	//! ���s���R
	u8 Reason;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillUseFailed()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillUseFailed(u8 InReason)
	{
		Reason = InReason;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Reason);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLUSEFAILED_H__

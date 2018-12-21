/**
 * @file PacketSkillUse.h
 * @brief スキル使用
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLUSE_H__
#define __PACKETSKILLUSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキル使用
 */
class PacketSkillUse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillUse; }

	

	//! 
u32 SkillId;
	//! 
u8 TargetType;
	//! 
u32 TargetUuid;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillUse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillUse(u32 InSkillId, u8 InTargetType, u32 InTargetUuid)
	{
		SkillId = InSkillId;
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&SkillId);
		pStream->Serialize(&TargetType);
		pStream->Serialize(&TargetUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLUSE_H__

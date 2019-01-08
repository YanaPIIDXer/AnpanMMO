/**
 * @file PacketDamage.h
 * @brief �_���[�W�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETDAMAGE_H__
#define __PACKETDAMAGE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �_���[�W�p�P�b�g
 */
class PacketDamage  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::Damage; }

	

	//! �^�[�Q�b�g�^�C�v
	u8 TargetType;
	//! �^�[�Q�b�g��UUID
	u32 TargetUuid;
	//! �_���[�W��
	s32 DamageValue;
	//! �_���[�W���HP
	s32 ResultHp;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketDamage()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketDamage(u8 InTargetType, u32 InTargetUuid, s32 InDamageValue, s32 InResultHp)
	{
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		DamageValue = InDamageValue;
		ResultHp = InResultHp;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&TargetType);
		pStream->Serialize(&TargetUuid);
		pStream->Serialize(&DamageValue);
		pStream->Serialize(&ResultHp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETDAMAGE_H__

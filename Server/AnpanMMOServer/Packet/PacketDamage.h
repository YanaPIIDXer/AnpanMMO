/**
 * @file PacketDamage.h
 * @brief ダメージ
 * @author NativePacketGenerator
 */

#ifndef __PACKETDAMAGE_H__
#define __PACKETDAMAGE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ダメージ
 */
class PacketDamage  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::Damage; }

	

	//! 
u8 TargetType;
	//! 
u32 TargetUuid;
	//! 
s32 DamageValue;
	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
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

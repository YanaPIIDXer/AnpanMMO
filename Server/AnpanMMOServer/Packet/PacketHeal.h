/**
 * @file PacketHeal.h
 * @brief 回復
 * @author NativePacketGenerator
 */

#ifndef __PACKETHEAL_H__
#define __PACKETHEAL_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 回復
 */
class PacketHeal  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::Heal; }

	

	//! 
u8 TargetType;
	//! 
u32 TargetUuid;
	//! 
s32 HealValue;
	//! 
s32 ResultHp;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketHeal()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketHeal(u8 InTargetType, u32 InTargetUuid, s32 InHealValue, s32 InResultHp)
	{
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		HealValue = InHealValue;
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
		pStream->Serialize(&HealValue);
		pStream->Serialize(&ResultHp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETHEAL_H__

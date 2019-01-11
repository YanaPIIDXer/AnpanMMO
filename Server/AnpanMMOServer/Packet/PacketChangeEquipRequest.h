/**
 * @file PacketChangeEquipRequest.h
 * @brief �����ύX���N�G�X�g�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETCHANGEEQUIPREQUEST_H__
#define __PACKETCHANGEEQUIPREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �����ύX���N�G�X�g�p�P�b�g
 */
class PacketChangeEquipRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ChangeEquipRequest; }

	

	//! �E�葕��
	u32 RightEquip;
	//! ���葕��
	u32 LeftEquip;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketChangeEquipRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketChangeEquipRequest(u32 InRightEquip, u32 InLeftEquip)
	{
		RightEquip = InRightEquip;
		LeftEquip = InLeftEquip;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&RightEquip);
		pStream->Serialize(&LeftEquip);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCHANGEEQUIPREQUEST_H__

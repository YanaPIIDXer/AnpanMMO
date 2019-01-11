/**
 * @file PacketChangeEquipResult.h
 * @brief �����ύX���ʃp�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETCHANGEEQUIPRESULT_H__
#define __PACKETCHANGEEQUIPRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �����ύX���ʃp�P�b�g
 */
class PacketChangeEquipResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ChangeEquipResult; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �E�葕���͊O���Ȃ�
		CanNotRemoveRightEquip,
		//! �������Ă��Ȃ�
		NotPossession,
		//! �G���[
		Error,
	};

	//! ���U���g�R�[�h
	u8 Result;
	//! �E�葕��
	u32 RightEquip;
	//! ���葕��
	u32 LeftEquip;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketChangeEquipResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketChangeEquipResult(u8 InResult, u32 InRightEquip, u32 InLeftEquip)
	{
		Result = InResult;
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
		pStream->Serialize(&Result);
		pStream->Serialize(&RightEquip);
		pStream->Serialize(&LeftEquip);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCHANGEEQUIPRESULT_H__

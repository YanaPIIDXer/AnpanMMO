/**
 * @file PacketAddExp.h
 * @brief �o���l�ǉ�
 * @author NativePacketGenerator
 */

#ifndef __PACKETADDEXP_H__
#define __PACKETADDEXP_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �o���l�ǉ�
 */
class PacketAddExp  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::AddExp; }

	

	//! �o���l
	s32 Exp;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAddExp()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAddExp(s32 InExp)
	{
		Exp = InExp;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Exp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETADDEXP_H__

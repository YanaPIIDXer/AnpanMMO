/**
 * @file PacketAddExp.h
 * @brief 経験値追加
 * @author NativePacketGenerator
 */

#ifndef __PACKETADDEXP_H__
#define __PACKETADDEXP_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 経験値追加
 */
class PacketAddExp  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::AddExp; }

	

	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Exp);
		
		return true;
	}
};

#endif		// #ifndef __PACKETADDEXP_H__

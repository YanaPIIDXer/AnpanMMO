/**
 * @file PacketTimeChange.h
 * @brief 時間変化通知
 * @author NativePacketGenerator
 */

#ifndef __PACKETTIMECHANGE_H__
#define __PACKETTIMECHANGE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief 時間変化通知
 */
class PacketTimeChange  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::TimeChange; }

	

	//! 
u32 MasterId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketTimeChange()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketTimeChange(u32 InMasterId)
	{
		MasterId = InMasterId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&MasterId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETTIMECHANGE_H__

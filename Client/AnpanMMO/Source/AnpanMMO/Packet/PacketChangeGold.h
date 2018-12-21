/**
 * @file PacketChangeGold.h
 * @brief �S�[���h�ω�
 * @author NativePacketGenerator
 */

#ifndef __PACKETCHANGEGOLD_H__
#define __PACKETCHANGEGOLD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �S�[���h�ω�
 */
class PacketChangeGold  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ChangeGold; }

	

	//! 
u32 Gold;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketChangeGold()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketChangeGold(u32 InGold)
	{
		Gold = InGold;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Gold);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCHANGEGOLD_H__

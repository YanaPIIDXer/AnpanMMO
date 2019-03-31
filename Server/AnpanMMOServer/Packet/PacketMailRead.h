/**
 * @file PacketMailRead.h
 * @brief ���[���J���p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILREAD_H__
#define __PACKETMAILREAD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ���[���J���p�P�b�g
 */
class PacketMailRead  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::MailRead; }

	

	//! �h�c
	u32 Id;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMailRead()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMailRead(u32 InId)
	{
		Id = InId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Id);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMAILREAD_H__

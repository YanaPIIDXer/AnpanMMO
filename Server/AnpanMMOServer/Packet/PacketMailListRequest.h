/**
 * @file PacketMailListRequest.h
 * @brief ���[�����X�g�v���p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILLISTREQUEST_H__
#define __PACKETMAILLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ���[�����X�g�v���p�P�b�g
 */
class PacketMailListRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::MailListRequest; }

	

	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMailListRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __PACKETMAILLISTREQUEST_H__

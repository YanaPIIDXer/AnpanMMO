/**
 * @file PacketMailList.h
 * @brief ���[�����X�g�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETMAILLIST_H__
#define __PACKETMAILLIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"
#include "MailData.h"
#include "PacketID.h"


/**
 * @brief ���[�����X�g�p�P�b�g
 */
class PacketMailList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::MailList; }

	

	//! ���[�����X�g
	FlexArray<MailData> List;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMailList()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketMailList(FlexArray<MailData> InList)
	{
		List = InList;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		List.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETMAILLIST_H__

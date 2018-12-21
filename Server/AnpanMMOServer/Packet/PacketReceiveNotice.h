/**
 * @file PacketReceiveNotice.h
 * @brief �ʒm
 * @author NativePacketGenerator
 */

#ifndef __PACKETRECEIVENOTICE_H__
#define __PACKETRECEIVENOTICE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "NoticeData.h"
#include "PacketID.h"


/**
 * @brief �ʒm
 */
class PacketReceiveNotice  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ReceiveNotice; }

	

	//! �ʒm�f�[�^
	NoticeData Notice;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketReceiveNotice()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketReceiveNotice(NoticeData InNotice)
	{
		Notice = InNotice;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Notice.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETRECEIVENOTICE_H__

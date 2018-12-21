/**
 * @file PacketReceiveNotice.h
 * @brief 通知
 * @author NativePacketGenerator
 */

#ifndef __PACKETRECEIVENOTICE_H__
#define __PACKETRECEIVENOTICE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "NoticeData.h"
#include "PacketID.h"


/**
 * @brief 通知
 */
class PacketReceiveNotice  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ReceiveNotice; }

	

	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Notice.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETRECEIVENOTICE_H__

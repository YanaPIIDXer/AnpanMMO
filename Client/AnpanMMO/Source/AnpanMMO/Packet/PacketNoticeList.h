/**
 * @file PacketNoticeList.h
 * @brief �ʒm���X�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETNOTICELIST_H__
#define __PACKETNOTICELIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "NoticeData.h"
#include "FlexArray.h"
#include "PacketID.h"


/**
 * @brief �ʒm���X�g
 */
class PacketNoticeList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::NoticeList; }

	

	//! �ʒm���X�g
	FlexArray<NoticeData> Notices;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketNoticeList()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketNoticeList(FlexArray<NoticeData> InNotices)
	{
		Notices = InNotices;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Notices.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETNOTICELIST_H__

/**
 * @file PacketNoticeList.h
 * @brief 通知リスト
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
 * @brief 通知リスト
 */
class PacketNoticeList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::NoticeList; }

	

	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Notices.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETNOTICELIST_H__

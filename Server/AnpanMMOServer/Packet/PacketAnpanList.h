/**
 * @file PacketAnpanList.h
 * @brief �A���p�����X�g�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETANPANLIST_H__
#define __PACKETANPANLIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"
#include "AnpanData.h"
#include "PacketID.h"


/**
 * @brief �A���p�����X�g�p�P�b�g
 */
class PacketAnpanList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::AnpanList; }

	

	//! �A���p�����X�g
	FlexArray<AnpanData> List;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAnpanList()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAnpanList(FlexArray<AnpanData> InList)
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

#endif		// #ifndef __PACKETANPANLIST_H__

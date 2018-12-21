/**
 * @file PacketAnpanList.h
 * @brief アンパンリスト
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
 * @brief アンパンリスト
 */
class PacketAnpanList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::AnpanList; }

	

	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		List.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETANPANLIST_H__

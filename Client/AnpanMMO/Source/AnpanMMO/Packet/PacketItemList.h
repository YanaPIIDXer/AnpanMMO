/**
 * @file PacketItemList.h
 * @brief ���O�C�����A�C�e�����X�g�ʒm
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMLIST_H__
#define __PACKETITEMLIST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ItemData.h"
#include "FlexArray.h"
#include "PacketID.h"


/**
 * @brief ���O�C�����A�C�e�����X�g�ʒm
 */
class PacketItemList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemList; }

	

	//! �A�C�e�����X�g
	FlexArray<ItemData> Items;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemList()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemList(FlexArray<ItemData> InItems)
	{
		Items = InItems;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Items.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMLIST_H__

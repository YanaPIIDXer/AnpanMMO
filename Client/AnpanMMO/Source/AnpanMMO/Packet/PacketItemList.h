/**
 * @file PacketItemList.h
 * @brief ログイン時アイテムリスト通知
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
 * @brief ログイン時アイテムリスト通知
 */
class PacketItemList  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemList; }

	

	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		Items.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMLIST_H__

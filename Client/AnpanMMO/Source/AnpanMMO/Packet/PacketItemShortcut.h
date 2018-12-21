/**
 * @file PacketItemShortcut.h
 * @brief ログイン時アイテムショートカット通知
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMSHORTCUT_H__
#define __PACKETITEMSHORTCUT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ログイン時アイテムショートカット通知
 */
class PacketItemShortcut  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemShortcut; }

	

	//! 
u32 ItemId1;
	//! 
u32 ItemId2;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemShortcut()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemShortcut(u32 InItemId1, u32 InItemId2)
	{
		ItemId1 = InItemId1;
		ItemId2 = InItemId2;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId1);
		pStream->Serialize(&ItemId2);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMSHORTCUT_H__

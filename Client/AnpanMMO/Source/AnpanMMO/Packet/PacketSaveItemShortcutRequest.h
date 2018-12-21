/**
 * @file PacketSaveItemShortcutRequest.h
 * @brief アイテムショートカット保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETSAVEITEMSHORTCUTREQUEST_H__
#define __PACKETSAVEITEMSHORTCUTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテムショートカット保存リクエスト
 */
class PacketSaveItemShortcutRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SaveItemShortcutRequest; }

	

	//! 
u32 ItemId1;
	//! 
u32 ItemId2;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSaveItemShortcutRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSaveItemShortcutRequest(u32 InItemId1, u32 InItemId2)
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

#endif		// #ifndef __PACKETSAVEITEMSHORTCUTREQUEST_H__

/**
 * @file PacketItemSubtractRequest.h
 * @brief アイテム破棄リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMSUBTRACTREQUEST_H__
#define __PACKETITEMSUBTRACTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテム破棄リクエスト
 */
class PacketItemSubtractRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemSubtractRequest; }

	

	//! 
u32 ItemId;
	//! 
u32 Count;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemSubtractRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemSubtractRequest(u32 InItemId, u32 InCount)
	{
		ItemId = InItemId;
		Count = InCount;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMSUBTRACTREQUEST_H__

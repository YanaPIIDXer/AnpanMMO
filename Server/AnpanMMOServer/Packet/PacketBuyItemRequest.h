/**
 * @file PacketBuyItemRequest.h
 * @brief �A�C�e���w���v���p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETBUYITEMREQUEST_H__
#define __PACKETBUYITEMREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �A�C�e���w���v���p�P�b�g
 */
class PacketBuyItemRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::BuyItemRequest; }

	

	//! �V���b�v�h�c
	u32 ShopId;
	//! �A�C�e���h�c
	u32 ItemId;
	//! ��
	u32 Count;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketBuyItemRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketBuyItemRequest(u32 InShopId, u32 InItemId, u32 InCount)
	{
		ShopId = InShopId;
		ItemId = InItemId;
		Count = InCount;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ShopId);
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __PACKETBUYITEMREQUEST_H__

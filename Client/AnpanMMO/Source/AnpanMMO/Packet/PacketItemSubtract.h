/**
 * @file PacketItemSubtract.h
 * @brief アイテム消費
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMSUBTRACT_H__
#define __PACKETITEMSUBTRACT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテム消費
 */
class PacketItemSubtract  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemSubtract; }

	

	//! 
u32 ItemId;
	//! 
u32 Count;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemSubtract()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemSubtract(u32 InItemId, u32 InCount)
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

#endif		// #ifndef __PACKETITEMSUBTRACT_H__

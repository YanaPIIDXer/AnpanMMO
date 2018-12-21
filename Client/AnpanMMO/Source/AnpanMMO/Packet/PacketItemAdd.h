/**
 * @file PacketItemAdd.h
 * @brief �A�C�e���ǉ�
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMADD_H__
#define __PACKETITEMADD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �A�C�e���ǉ�
 */
class PacketItemAdd  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemAdd; }

	

	//! �A�C�e���h�c
	u32 ItemId;
	//! ��
	u32 Count;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemAdd()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemAdd(u32 InItemId, u32 InCount)
	{
		ItemId = InItemId;
		Count = InCount;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMADD_H__

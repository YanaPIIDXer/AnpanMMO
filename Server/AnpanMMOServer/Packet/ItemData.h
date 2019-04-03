/**
 * @file ItemData.h
 * @brief �A�C�e���f�[�^�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __ITEMDATA_H__
#define __ITEMDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief �A�C�e���f�[�^�p�P�b�g
 */
class ItemData 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	

	

	//! �A�C�e����
	u32 ItemId;
	//! ��
	u32 Count;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	ItemData()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	ItemData(u32 InItemId, u32 InCount)
	{
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
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __ITEMDATA_H__

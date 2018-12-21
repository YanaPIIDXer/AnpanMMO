/**
 * @file PacketItemUse.h
 * @brief アイテム使用
 * @author NativePacketGenerator
 */

#ifndef __PACKETITEMUSE_H__
#define __PACKETITEMUSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテム使用
 */
class PacketItemUse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::ItemUse; }

	

	//! 
u32 ItemId;
	//! 
u8 TargetType;
	//! 
u32 TargetUuid;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemUse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketItemUse(u32 InItemId, u8 InTargetType, u32 InTargetUuid)
	{
		ItemId = InItemId;
		TargetType = InTargetType;
		TargetUuid = InTargetUuid;
		
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
		pStream->Serialize(&TargetType);
		pStream->Serialize(&TargetUuid);
		
		return true;
	}
};

#endif		// #ifndef __PACKETITEMUSE_H__

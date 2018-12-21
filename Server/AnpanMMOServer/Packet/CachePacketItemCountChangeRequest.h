/**
 * @file CachePacketItemCountChangeRequest.h
 * @brief アイテム数変化リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETITEMCOUNTCHANGEREQUEST_H__
#define __CACHEPACKETITEMCOUNTCHANGEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief アイテム数変化リクエスト
 */
class CachePacketItemCountChangeRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemCountChangeRequest; }

	

	//! 
u32 CharacterId;
	//! 
u32 ItemId;
	//! 
u32 Count;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketItemCountChangeRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketItemCountChangeRequest(u32 InClientId, u32 InCharacterId, u32 InItemId, u32 InCount)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
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
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&ItemId);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMCOUNTCHANGEREQUEST_H__

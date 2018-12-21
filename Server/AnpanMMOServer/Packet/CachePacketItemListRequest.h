/**
 * @file CachePacketItemListRequest.h
 * @brief アイテムリストリクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETITEMLISTREQUEST_H__
#define __CACHEPACKETITEMLISTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief アイテムリストリクエスト
 */
class CachePacketItemListRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemListRequest; }

	

	//! 
u32 CharacterId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketItemListRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketItemListRequest(u32 InClientId, u32 InCharacterId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		
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
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMLISTREQUEST_H__

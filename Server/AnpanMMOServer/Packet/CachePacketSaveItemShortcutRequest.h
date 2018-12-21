/**
 * @file CachePacketSaveItemShortcutRequest.h
 * @brief アイテムショートカット保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVEITEMSHORTCUTREQUEST_H__
#define __CACHEPACKETSAVEITEMSHORTCUTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief アイテムショートカット保存リクエスト
 */
class CachePacketSaveItemShortcutRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveItemShortcutRequest; }

	

	//! 
u32 CharacterId;
	//! 
u32 ItemId1;
	//! 
u32 ItemId2;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveItemShortcutRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveItemShortcutRequest(u32 InClientId, u32 InCharacterId, u32 InItemId1, u32 InItemId2)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
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
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&ItemId1);
		pStream->Serialize(&ItemId2);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEITEMSHORTCUTREQUEST_H__

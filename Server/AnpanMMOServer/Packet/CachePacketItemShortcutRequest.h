/**
 * @file CachePacketItemShortcutRequest.h
 * @brief �A�C�e���V���[�g�J�b�g���N�G�X�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETITEMSHORTCUTREQUEST_H__
#define __CACHEPACKETITEMSHORTCUTREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �A�C�e���V���[�g�J�b�g���N�G�X�g
 */
class CachePacketItemShortcutRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemShortcutRequest; }

	

	//! �L�����N�^�h�c
	u32 CharacterId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketItemShortcutRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketItemShortcutRequest(u32 InClientId, u32 InCharacterId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMSHORTCUTREQUEST_H__

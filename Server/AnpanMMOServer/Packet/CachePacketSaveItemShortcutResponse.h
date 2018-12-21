/**
 * @file CachePacketSaveItemShortcutResponse.h
 * @brief �A�C�e���V���[�g�J�b�g�ۑ����X�|���X
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__
#define __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �A�C�e���V���[�g�J�b�g�ۑ����X�|���X
 */
class CachePacketSaveItemShortcutResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSaveItemShortcutResponse; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Error,
	};

	//! ����
	u8 Result;
	//! �A�C�e���h�c�P
	u32 ItemId1;
	//! �A�C�e���h�c�Q
	u32 ItemId2;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveItemShortcutResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketSaveItemShortcutResponse(u32 InClientId, u8 InResult, u32 InItemId1, u32 InItemId2)
	{
		ClientId = InClientId;
		Result = InResult;
		ItemId1 = InItemId1;
		ItemId2 = InItemId2;
		
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
		pStream->Serialize(&Result);
		pStream->Serialize(&ItemId1);
		pStream->Serialize(&ItemId2);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSAVEITEMSHORTCUTRESPONSE_H__

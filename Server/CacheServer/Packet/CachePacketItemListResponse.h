/**
 * @file CachePacketItemListResponse.h
 * @brief �A�C�e�����X�g���X�|���X�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETITEMLISTRESPONSE_H__
#define __CACHEPACKETITEMLISTRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "ItemData.h"
#include "FlexArray.h"
#include "CacheServerPacketID.h"


/**
 * @brief �A�C�e�����X�g���X�|���X�p�P�b�g
 */
class CachePacketItemListResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheItemListResponse; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Error,
	};

	//! ����
	u8 Result;
	//! �A�C�e�����X�g
	FlexArray<ItemData> Items;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketItemListResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketItemListResponse(u32 InClientId, u8 InResult, FlexArray<ItemData> InItems)
	{
		ClientId = InClientId;
		Result = InResult;
		Items = InItems;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Result);
		Items.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETITEMLISTRESPONSE_H__

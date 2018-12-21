/**
 * @file CachePacketCreateCharacterResult.h
 * @brief キャラクタ作成結果
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCREATECHARACTERRESULT_H__
#define __CACHEPACKETCREATECHARACTERRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief キャラクタ作成結果
 */
class CachePacketCreateCharacterResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheCreateCharacterResult; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketCreateCharacterResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketCreateCharacterResult(u32 InClientId, u8 InResult)
	{
		ClientId = InClientId;
		Result = InResult;
		
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
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCREATECHARACTERRESULT_H__

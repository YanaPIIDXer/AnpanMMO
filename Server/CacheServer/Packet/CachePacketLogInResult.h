/**
 * @file CachePacketLogInResult.h
 * @brief ログインリクエスト結果
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETLOGINRESULT_H__
#define __CACHEPACKETLOGINRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ログインリクエスト結果
 */
class CachePacketLogInResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheLogInResult; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		NoCharacter = キャラクタがいない,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	//! 
s32 CustomerId;
	//! 
u32 LastAreaId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketLogInResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketLogInResult(u32 InClientId, u8 InResult, s32 InCustomerId, u32 InLastAreaId)
	{
		ClientId = InClientId;
		Result = InResult;
		CustomerId = InCustomerId;
		LastAreaId = InLastAreaId;
		
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
		pStream->Serialize(&CustomerId);
		pStream->Serialize(&LastAreaId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGINRESULT_H__

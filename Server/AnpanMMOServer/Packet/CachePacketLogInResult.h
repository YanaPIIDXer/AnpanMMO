/**
 * @file CachePacketLogInResult.h
 * @brief ���O�C�����N�G�X�g����
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETLOGINRESULT_H__
#define __CACHEPACKETLOGINRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ���O�C�����N�G�X�g����
 */
class CachePacketLogInResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheLogInResult; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �L�����N�^�����Ȃ�
		NoCharacter,
		//! �G���[
		Error,
	};

	//! ����
	u8 Result;
	//! �J�X�^�}ID
	s32 CustomerId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketLogInResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketLogInResult(u32 InClientId, u8 InResult, s32 InCustomerId)
	{
		ClientId = InClientId;
		Result = InResult;
		CustomerId = InCustomerId;
		
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
		pStream->Serialize(&CustomerId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETLOGINRESULT_H__

/**
 * @file CachePacketScriptFlagResponse.h
 * @brief �X�N���v�g�t���O���X�|���X
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSCRIPTFLAGRESPONSE_H__
#define __CACHEPACKETSCRIPTFLAGRESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �X�N���v�g�t���O���X�|���X
 */
class CachePacketScriptFlagResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheScriptFlagResponse; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Error,
	};

	//! ����
	u8 Result;
	//! �r�b�g�t�B�[���h�P
	u32 BitField1;
	//! �r�b�g�t�B�[���h�Q
	u32 BitField2;
	//! �r�b�g�t�B�[���h�R
	u32 BitField3;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketScriptFlagResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketScriptFlagResponse(u32 InClientId, u8 InResult, u32 InBitField1, u32 InBitField2, u32 InBitField3)
	{
		ClientId = InClientId;
		Result = InResult;
		BitField1 = InBitField1;
		BitField2 = InBitField2;
		BitField3 = InBitField3;
		
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
		pStream->Serialize(&BitField1);
		pStream->Serialize(&BitField2);
		pStream->Serialize(&BitField3);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSCRIPTFLAGRESPONSE_H__

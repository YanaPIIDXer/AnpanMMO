/**
 * @file CachePacketScriptFlagSaveRequest.h
 * @brief �X�N���v�g�t���O�ۑ����N�G�X�g�p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSCRIPTFLAGSAVEREQUEST_H__
#define __CACHEPACKETSCRIPTFLAGSAVEREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �X�N���v�g�t���O�ۑ����N�G�X�g�p�P�b�g
 */
class CachePacketScriptFlagSaveRequest  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheScriptFlagSaveRequest; }

	

	//! �L�����N�^�h�c
	u32 CharacterId;
	//! �r�b�g�t�B�[���h�P
	u32 BitField1;
	//! �r�b�g�t�B�[���h�Q
	u32 BitField2;
	//! �r�b�g�t�B�[���h�R
	u32 BitField3;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketScriptFlagSaveRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketScriptFlagSaveRequest(u32 InClientId, u32 InCharacterId, u32 InBitField1, u32 InBitField2, u32 InBitField3)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
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
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&BitField1);
		pStream->Serialize(&BitField2);
		pStream->Serialize(&BitField3);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSCRIPTFLAGSAVEREQUEST_H__

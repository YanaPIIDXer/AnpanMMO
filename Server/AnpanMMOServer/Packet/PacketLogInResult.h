/**
 * @file PacketLogInResult.h
 * @brief ���O�C�����N�G�X�g���ʃp�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETLOGINRESULT_H__
#define __PACKETLOGINRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ���O�C�����N�G�X�g���ʃp�P�b�g
 */
class PacketLogInResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::LogInResult; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �_�u�����O�C��
		DoubleLogIn,
		//! �L�����N�^�����݂��Ȃ�
		NoCharacter,
		//! �a�`�m����Ă���
		Bunned,
		//! �G���[
		Error,
	};

	//! ����
	u8 Result;
	//! UUID
	s32 Uuid;
	//! �ŏI���O�A�E�g�G���A�h�c
	u32 LastAreaId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketLogInResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketLogInResult(u8 InResult, s32 InUuid, u32 InLastAreaId)
	{
		Result = InResult;
		Uuid = InUuid;
		LastAreaId = InLastAreaId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&Uuid);
		pStream->Serialize(&LastAreaId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETLOGINRESULT_H__

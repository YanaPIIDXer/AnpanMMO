/**
 * @file PacketPartyExitResult.h
 * @brief �p�[�e�B���E����
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYEXITRESULT_H__
#define __PACKETPARTYEXITRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �p�[�e�B���E����
 */
class PacketPartyExitResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyExitResult; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Error,
	};

	//! ����
	u8 Result;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyExitResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyExitResult(u8 InResult)
	{
		Result = InResult;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYEXITRESULT_H__

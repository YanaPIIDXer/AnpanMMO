/**
 * @file PacketPartyDissolutionResult.h
 * @brief �p�[�e�B���U���ʃp�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYDISSOLUTIONRESULT_H__
#define __PACKETPARTYDISSOLUTIONRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �p�[�e�B���U���ʃp�P�b�g
 */
class PacketPartyDissolutionResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyDissolutionResult; }

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
	PacketPartyDissolutionResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyDissolutionResult(u8 InResult)
	{
		Result = InResult;
		
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
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYDISSOLUTIONRESULT_H__

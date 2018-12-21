/**
 * @file PacketCreateCharacterResult.h
 * @brief �L�����N�^�쐬����
 * @author NativePacketGenerator
 */

#ifndef __PACKETCREATECHARACTERRESULT_H__
#define __PACKETCREATECHARACTERRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �L�����N�^�쐬����
 */
class PacketCreateCharacterResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::CreateCharacterResult; }

	enum ResultCode
	{
		//! 
		Success = ����,
		//! 
		TooLongName = �������閼�O,
		//! 
		EmptyName = ���O����,
		//! 
		Error = �G���[,
	};

	//! 
u8 Result;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketCreateCharacterResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketCreateCharacterResult(u8 InResult)
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

#endif		// #ifndef __PACKETCREATECHARACTERRESULT_H__

/**
 * @file PacketAreaMoveResponse.h
 * @brief �G���A�ړ����X�|���X
 * @author NativePacketGenerator
 */

#ifndef __PACKETAREAMOVERESPONSE_H__
#define __PACKETAREAMOVERESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �G���A�ړ����X�|���X
 */
class PacketAreaMoveResponse  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::AreaMoveResponse; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Fatal,
	};

	//! ����
	u8 Result;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAreaMoveResponse()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketAreaMoveResponse(u8 InResult)
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

#endif		// #ifndef __PACKETAREAMOVERESPONSE_H__

/**
 * @file PacketLogInRequest.h
 * @brief ログインリクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETLOGINREQUEST_H__
#define __PACKETLOGINREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief ログインリクエスト
 */
class PacketLogInRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::LogInRequest; }

	

	//! 
std::string UserCode;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketLogInRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketLogInRequest(std::string InUserCode)
	{
		UserCode = InUserCode;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&UserCode);
		
		return true;
	}
};

#endif		// #ifndef __PACKETLOGINREQUEST_H__

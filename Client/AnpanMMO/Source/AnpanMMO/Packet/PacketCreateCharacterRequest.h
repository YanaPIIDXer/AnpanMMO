/**
 * @file PacketCreateCharacterRequest.h
 * @brief キャラクタ作成リクエスト
 * @author NativePacketGenerator
 */

#ifndef __PACKETCREATECHARACTERREQUEST_H__
#define __PACKETCREATECHARACTERREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief キャラクタ作成リクエスト
 */
class PacketCreateCharacterRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::CreateCharacterRequest; }

	

	//! 
std::string CharacterName;
	//! 
u8 Job;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketCreateCharacterRequest()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketCreateCharacterRequest(std::string InCharacterName, u8 InJob)
	{
		CharacterName = InCharacterName;
		Job = InJob;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&CharacterName);
		pStream->Serialize(&Job);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCREATECHARACTERREQUEST_H__

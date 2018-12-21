/**
 * @file PacketPartyCreateResult.h
 * @brief パーティ作成結果
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYCREATERESULT_H__
#define __PACKETPARTYCREATERESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティ作成結果
 */
class PacketPartyCreateResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyCreateResult; }

	enum ResultCode
	{
		//! 
		Success,
		//! 
		AlreadyJoin,
		//! 
		Error,
	};

	//! 
u8 Result;
	//! 
u32 PartyId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyCreateResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyCreateResult(u8 InResult, u32 InPartyId)
	{
		Result = InResult;
		PartyId = InPartyId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&PartyId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYCREATERESULT_H__

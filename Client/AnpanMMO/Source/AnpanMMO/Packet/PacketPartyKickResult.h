/**
 * @file PacketPartyKickResult.h
 * @brief パーティメンバキック結果
 * @author NativePacketGenerator
 */

#ifndef __PACKETPARTYKICKRESULT_H__
#define __PACKETPARTYKICKRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief パーティメンバキック結果
 */
class PacketPartyKickResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::PartyKickResult; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyKickResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketPartyKickResult(u8 InResult)
	{
		Result = InResult;
		
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
		
		return true;
	}
};

#endif		// #ifndef __PACKETPARTYKICKRESULT_H__

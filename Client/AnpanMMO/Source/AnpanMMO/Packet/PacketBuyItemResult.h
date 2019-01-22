/**
 * @file PacketBuyItemResult.h
 * @brief �A�C�e���w�����ʃp�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETBUYITEMRESULT_H__
#define __PACKETBUYITEMRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �A�C�e���w�����ʃp�P�b�g
 */
class PacketBuyItemResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::BuyItemResult; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �����ȃV���b�v�h�c
		InvalidShopId,
		//! �����Ă��Ȃ�
		NotSelling,
		//! �����ȃA�C�e��
		InvalidItem,
		//! �S�[���h������Ȃ�
		NotEnougthGold,
	};

	//! ���U���g�R�[�h
	u8 Result;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketBuyItemResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketBuyItemResult(u8 InResult)
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

#endif		// #ifndef __PACKETBUYITEMRESULT_H__

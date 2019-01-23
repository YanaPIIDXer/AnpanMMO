/**
 * @file PacketSellItemResult.h
 * @brief �A�C�e�����p���ʃp�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __PACKETSELLITEMRESULT_H__
#define __PACKETSELLITEMRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �A�C�e�����p���ʃp�P�b�g
 */
class PacketSellItemResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SellItemResult; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �����ȃV���b�v�h�c
		InvalidShopId,
		//! �����ȃA�C�e��
		InvalidItem,
		//! �A�C�e���������Ă��Ȃ�
		NotHaveItem,
	};

	//! ���U���g�R�[�h
	u8 Result;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSellItemResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSellItemResult(u8 InResult)
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

#endif		// #ifndef __PACKETSELLITEMRESULT_H__
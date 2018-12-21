/**
 * @file CachePacketGoldSave.h
 * @brief ゴールド保存リクエスト
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETGOLDSAVE_H__
#define __CACHEPACKETGOLDSAVE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ゴールド保存リクエスト
 */
class CachePacketGoldSave  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheGoldSave; }

	

	//! 
u32 CharacterId;
	//! 
u32 Gold;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketGoldSave()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketGoldSave(u32 InClientId, u32 InCharacterId, u32 InGold)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		Gold = InGold;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&Gold);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETGOLDSAVE_H__

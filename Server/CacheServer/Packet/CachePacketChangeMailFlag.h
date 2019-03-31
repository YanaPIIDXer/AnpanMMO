/**
 * @file CachePacketChangeMailFlag.h
 * @brief ���[���t���O�؂�ւ��p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETCHANGEMAILFLAG_H__
#define __CACHEPACKETCHANGEMAILFLAG_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ���[���t���O�؂�ւ��p�P�b�g
 */
class CachePacketChangeMailFlag  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheChangeMailFlag; }

	

	//! �h�c
	u32 Id;
	//! �t���O
	u8 Flag;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketChangeMailFlag()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketChangeMailFlag(u32 InClientId, u32 InId, u8 InFlag)
	{
		ClientId = InClientId;
		Id = InId;
		Flag = InFlag;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ProcessPacketBase::Serialize(pStream);
		pStream->Serialize(&Id);
		pStream->Serialize(&Flag);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETCHANGEMAILFLAG_H__

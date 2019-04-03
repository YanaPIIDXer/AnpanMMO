/**
 * @file CachePacketMailRead.h
 * @brief ���[���J���p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETMAILREAD_H__
#define __CACHEPACKETMAILREAD_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ���[���J���p�P�b�g
 */
class CachePacketMailRead  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheMailRead; }

	

	//! �h�c
	u32 Id;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketMailRead()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketMailRead(u32 InClientId, u32 InId)
	{
		ClientId = InClientId;
		Id = InId;
		
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
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETMAILREAD_H__

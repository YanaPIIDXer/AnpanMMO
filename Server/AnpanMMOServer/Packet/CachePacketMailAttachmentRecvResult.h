/**
 * @file CachePacketMailAttachmentRecvResult.h
 * @brief ���[���Y�t����M���ʃp�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETMAILATTACHMENTRECVRESULT_H__
#define __CACHEPACKETMAILATTACHMENTRECVRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief ���[���Y�t����M���ʃp�P�b�g
 */
class CachePacketMailAttachmentRecvResult  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheMailAttachmentRecvResult; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Error,
	};

	//! ���ʃR�[�h
	u8 Result;
	//! ���
	u8 Type;
	//! �h�c
	u32 Id;
	//! ����
	u32 Count;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketMailAttachmentRecvResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketMailAttachmentRecvResult(u32 InClientId, u8 InResult, u8 InType, u32 InId, u32 InCount)
	{
		ClientId = InClientId;
		Result = InResult;
		Type = InType;
		Id = InId;
		Count = InCount;
		
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
		pStream->Serialize(&Result);
		pStream->Serialize(&Type);
		pStream->Serialize(&Id);
		pStream->Serialize(&Count);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETMAILATTACHMENTRECVRESULT_H__

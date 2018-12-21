/**
 * @file PacketSkillTreeOpenResult.h
 * @brief �X�L���c���[�J������
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLTREEOPENRESULT_H__
#define __PACKETSKILLTREEOPENRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �X�L���c���[�J������
 */
class PacketSkillTreeOpenResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillTreeOpenResult; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �S�[���h������Ȃ�
		NotEnoughCost,
		//! �e���J����Ă��Ȃ�
		NotOpenedParent,
		//! ���x��������Ȃ�
		NotEnoughLevel,
		//! ���ɊJ����Ă���
		AlreadyOpened,
		//! �G���[
		Error,
	};

	//! ����
	u8 Result;
	//! �m�[�h�h�c
	u32 NodeId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillTreeOpenResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillTreeOpenResult(u8 InResult, u32 InNodeId)
	{
		Result = InResult;
		NodeId = InNodeId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param[in] pStream �X�g���[��
	 * @retrn ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&NodeId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEOPENRESULT_H__

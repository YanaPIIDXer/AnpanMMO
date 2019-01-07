/**
 * @file CachePacketOpenSkillTree.h
 * @brief �X�L���c���[�J���p�P�b�g
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETOPENSKILLTREE_H__
#define __CACHEPACKETOPENSKILLTREE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief �X�L���c���[�J���p�P�b�g
 */
class CachePacketOpenSkillTree  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheOpenSkillTree; }

	

	//! �L�����N�^�h�c
	u32 CharacterId;
	//! �m�[�h�h�c
	u32 NodeId;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketOpenSkillTree()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	CachePacketOpenSkillTree(u32 InClientId, u32 InCharacterId, u32 InNodeId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		NodeId = InNodeId;
		
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
		pStream->Serialize(&CharacterId);
		pStream->Serialize(&NodeId);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETOPENSKILLTREE_H__

/**
 * @file PacketSkillTreeOpenResult.h
 * @brief スキルツリー開放結果
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLTREEOPENRESULT_H__
#define __PACKETSKILLTREEOPENRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキルツリー開放結果
 */
class PacketSkillTreeOpenResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillTreeOpenResult; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		NotEnoughCost = ゴールドが足りない,
		//! 
		NotOpenedParent = 親が開かれていない,
		//! 
		NotEnoughLevel = レベルが足りない,
		//! 
		AlreadyOpened = 既に開かれている,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	//! 
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
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&NodeId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEOPENRESULT_H__

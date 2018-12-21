/**
 * @file PacketSkillUseFailed.h
 * @brief スキル使用失敗
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLUSEFAILED_H__
#define __PACKETSKILLUSEFAILED_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキル使用失敗
 */
class PacketSkillUseFailed  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillUseFailed; }

	enum ReasonType
	{
		//! 
		RecastTime = リキャスト中,
		//! 
		Cancel = キャンセル,
		//! 
		TargetDisappeared = ターゲット消失,
	};

	//! 
u8 Reason;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillUseFailed()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSkillUseFailed(u8 InReason)
	{
		Reason = InReason;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Reason);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLUSEFAILED_H__

/**
 * @file CachePacketOpenSkillTree.h
 * @brief スキルツリー開放
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETOPENSKILLTREE_H__
#define __CACHEPACKETOPENSKILLTREE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief スキルツリー開放
 */
class CachePacketOpenSkillTree  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheOpenSkillTree; }

	

	//! 
u32 CharacterId;
	//! 
u32 NodeId;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketOpenSkillTree()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketOpenSkillTree(u32 InClientId, u32 InCharacterId, u32 InNodeId)
	{
		ClientId = InClientId;
		CharacterId = InCharacterId;
		NodeId = InNodeId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
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

/**
 * @file PacketSkillTreeOpenRequest.h
 * @brief スキルツリー開放要求
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLTREEOPENREQUEST_H__
#define __PACKETSKILLTREEOPENREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキルツリー開放要求
 */
class PacketSkillTreeOpenRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillTreeOpenRequest; }

	

	//! 
u32 NodeId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillTreeOpenRequest()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillTreeOpenRequest(u32 InNodeId)
	{
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
		pStream->Serialize(&NodeId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEOPENREQUEST_H__

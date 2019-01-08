/**
 * @file PacketSkillTreeOpenRequest.h
 * @brief スキルツリー開放要求パケット
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLTREEOPENREQUEST_H__
#define __PACKETSKILLTREEOPENREQUEST_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief スキルツリー開放要求パケット
 */
class PacketSkillTreeOpenRequest  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillTreeOpenRequest; }

	

	//! ノードＩＤ
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
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&NodeId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEOPENREQUEST_H__

/**
 * @file SkillTreeNode.h
 * @brief スキルツリーノードパケット
 * @author NativePacketGenerator
 */

#ifndef __SKILLTREENODE_H__
#define __SKILLTREENODE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief スキルツリーノードパケット
 */
class SkillTreeNode 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	

	enum NodeState
	{
		//! 閉じている
		Closed,
		//! 開いている
		Open,
	};

	//! ノードＩＤ
	u32 NodeId;
	//! ステート
	u8 State;
	

	/**
	 * @brief コンストラクタ
	 */
	SkillTreeNode()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	SkillTreeNode(u32 InNodeId, u8 InState)
	{
		NodeId = InNodeId;
		State = InState;
		
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
		pStream->Serialize(&State);
		
		return true;
	}
};

#endif		// #ifndef __SKILLTREENODE_H__

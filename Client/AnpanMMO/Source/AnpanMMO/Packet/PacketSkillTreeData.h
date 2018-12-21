/**
 * @file PacketSkillTreeData.h
 * @brief スキルツリーデータ
 * @author NativePacketGenerator
 */

#ifndef __PACKETSKILLTREEDATA_H__
#define __PACKETSKILLTREEDATA_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "FlexArray.h"
#include "SkillTreeNode.h"
#include "PacketID.h"


/**
 * @brief スキルツリーデータ
 */
class PacketSkillTreeData  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillTreeData; }

	

	//! 
	FlexArray<SkillTreeNode> ノードリスト;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillTreeData()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillTreeData(FlexArray<SkillTreeNode> Inノードリスト)
	{
		ノードリスト = Inノードリスト;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		ノードリスト.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEDATA_H__

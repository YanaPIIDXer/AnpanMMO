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
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::SkillTreeOpenResult; }

	enum ResultCode
	{
		//! 成功
		Success,
		//! ゴールドが足りない
		NotEnoughCost,
		//! 親が開かれていない
		NotOpenedParent,
		//! レベルが足りない
		NotEnoughLevel,
		//! 既に開かれている
		AlreadyOpened,
		//! エラー
		Error,
	};

	//! 結果
	u8 Result;
	//! ノードＩＤ
	u32 NodeId;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillTreeOpenResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketSkillTreeOpenResult(u8 InResult, u32 InNodeId)
	{
		Result = InResult;
		NodeId = InNodeId;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrn 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&NodeId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEOPENRESULT_H__

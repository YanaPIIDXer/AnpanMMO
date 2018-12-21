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
	 * @returns パケットＩＤ
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
	 * @param in pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&NodeId);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSKILLTREEOPENRESULT_H__

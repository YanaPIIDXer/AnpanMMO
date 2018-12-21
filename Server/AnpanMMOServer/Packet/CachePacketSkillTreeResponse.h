/**
 * @file CachePacketSkillTreeResponse.h
 * @brief スキルツリーレスポンス
 * @author NativePacketGenerator
 */

#ifndef __CACHEPACKETSKILLTREERESPONSE_H__
#define __CACHEPACKETSKILLTREERESPONSE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "ProcessPacketBase.h"
#include "CacheServerPacketID.h"


/**
 * @brief スキルツリーレスポンス
 */
class CachePacketSkillTreeResponse  : public ProcessPacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return CachePacketID::CacheSkillTreeResponse; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	//! 
FlexArray<u32> OpenedList;
	

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSkillTreeResponse()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	CachePacketSkillTreeResponse(u32 InClientId, u8 InResult, FlexArray<u32> InOpenedList)
	{
		ClientId = InClientId;
		Result = InResult;
		OpenedList = InOpenedList;
		
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
		pStream->Serialize(&Result);
		OpenedList.Serialize(pStream);
		
		return true;
	}
};

#endif		// #ifndef __CACHEPACKETSKILLTREERESPONSE_H__

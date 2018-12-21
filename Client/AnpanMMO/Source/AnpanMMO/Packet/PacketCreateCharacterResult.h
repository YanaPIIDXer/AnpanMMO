/**
 * @file PacketCreateCharacterResult.h
 * @brief キャラクタ作成結果
 * @author NativePacketGenerator
 */

#ifndef __PACKETCREATECHARACTERRESULT_H__
#define __PACKETCREATECHARACTERRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief キャラクタ作成結果
 */
class PacketCreateCharacterResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @returns パケットＩＤ
	 */
	virtual u8 GetPacketID() const { return PacketID::CreateCharacterResult; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		TooLongName = 長すぎる名前,
		//! 
		EmptyName = 名前が空欄,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	

	/**
	 * @brief コンストラクタ
	 */
	PacketCreateCharacterResult()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	PacketCreateCharacterResult(u8 InResult)
	{
		Result = InResult;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @retrns 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		
		return true;
	}
};

#endif		// #ifndef __PACKETCREATECHARACTERRESULT_H__

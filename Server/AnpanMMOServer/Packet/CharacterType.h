/**
 * @file CharacterType.h
 * @brief キャラクタータイプパケット
 * @author NativePacketGenerator
 */

#ifndef __CHARACTERTYPE_H__
#define __CHARACTERTYPE_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief キャラクタータイプパケット
 */
class CharacterType 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	

	enum Type
	{
		//! プレイヤー
		Player,
		//! 敵（アンパン）
		Enemy,
	};

	

	/**
	 * @brief コンストラクタ
	 */
	CharacterType()
	{
	}

	/**
	 * @brief コンストラクタ
	 */
	


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief シリアライズ
	 * @param[in] pStream ストリーム
	 * @return 成功したらtrueを返す。
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __CHARACTERTYPE_H__

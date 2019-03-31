/**
 * @file CharacterJob.h
 * @brief ジョブパケット
 * @author NativePacketGenerator
 */

#ifndef __CHARACTERJOB_H__
#define __CHARACTERJOB_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"


/**
 * @brief ジョブパケット
 */
class CharacterJob 
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief パケットＩＤ取得.
	 * @return パケットＩＤ
	 */
	

	enum Type
	{
		//! ファイター
		Fighter,
		//! ソーサラー
		Sorcerer,
		//! ヒーラー
		Healer,
		//! ランサー
		Lancer,
	};

	

	/**
	 * @brief コンストラクタ
	 */
	CharacterJob()
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

#endif		// #ifndef __CHARACTERJOB_H__

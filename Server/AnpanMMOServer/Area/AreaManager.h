/**
 * @file AreaManager.cpp
 * @brief エリア管理クラス
 * @author YanaP
 */
#ifndef __AREAMANAGER_H__
#define __AREAMANAGER_H__

#include <boost/unordered_map.hpp>
#include "AreaBase.h"

class Client;
class MemoryStreamInterface;

/**
 * @brief エリア管理
 */
class AreaManager : public noncopyable
{

private:		// 別名定義.

	typedef shared_ptr<AreaBase> AreaSharedPtr;
	typedef unordered_map<u32, AreaSharedPtr> AreaMap;

public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~AreaManager() {}

	/**
	 * @fn void Initialize()
	 * @brief 初期化
	 */
	void Initialize();

	/**
	 * @fn AreaPtr Get(u32 ID) const
	 * @brief 取得
	 * @param[in] ID エリアＩＤ
	 * @return エリアへのweak_ptr
	 */
	AreaPtr Get(u32 ID) const;

	/**
	 * @fn void Poll(int DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	void Poll(int DeltaTime);

	/**
	 * @fn AreaPtr CreateInstanceArea(u32 AreaId)
	 * @brief インスタンスエリアを生成
	 * @param[in] AreaId エリアマスタのＩＤ
	 * @return AreaPtr インスタンスエリアへのweak_ptr
	 */
	AreaPtr CreateInstanceArea(u32 AreaId);

private:

	// エリアマップ
	AreaMap Areas;

	// 次に発行するインスタンスマップのUUID
	u32 NextInstanceAreaUuid;


	// ========== Singleton ===============

public:

	/**
	 * @fn static AreaManager &GetInstance()
	 * @brief シングルトンインスタンスを取得
	 * @return インスタンス
	 */
	static AreaManager &GetInstance() { return Instance; }

private:

	AreaManager();
	static AreaManager Instance;

};

#endif		// #ifndef __AREAMANAGER_H__

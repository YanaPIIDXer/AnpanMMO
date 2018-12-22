/**
 * @file InstanceArea.cpp
 * @brief インスタンスエリアクラス
 * @author YanaP
 */
#ifndef __INSTANCEAREA_H__
#define __INSTANCEAREA_H__

#include "AreaBase.h"

struct AreaItem;

/**
 * @brief インスタンスエリア
 */
class InstanceArea : public AreaBase
{

public:

	/**
	 * @brief コンストラクタ
	 */
	InstanceArea(u32 InUuid, const AreaItem *pItem);

	/**
	 * @brief デストラクタ
	 */
	virtual ~InstanceArea() {}

	/**
	 * @fn virtual void Initialize()
	 * @ brief 初期化
	 */
	virtual void Initialize();

	/**
	 * @fn virtual u32 GetId() const
	 * @brief ＩＤ取得
	 * @details インスタンスエリアに割り振られたＵＵＩＤを返す。
	 * @return ID
	 */
	virtual u32 GetId() const { return Uuid; }

	/**
	 * @fn virtual bool IsAbleDelete() const
	 * @brief 消去可能か？
	 * @details プレイヤーキャラがいなくなったら消去可能になる。
	 * @return 消去可能ならtrueを返す。
	 */
	virtual bool IsAbleDelete() const;

	/**
	 * @fn virtual bool IsInstance() const
	 * @brief インスタンスエリアか？
	 * @return インスタンスエリアなのでtrueを返す。
	 */
	virtual bool IsInstance() const { return true; }

protected:

	/**
	 * @fn virtual void Update()
	 * @brief 更新処理
	 */
	virtual void Update();

private:

	// UUID
	u32 Uuid;

	// インスタンス情報マスタＩＤ
	u32 InfoMasterId;

	// 脱出ポイント生成済みか？
	bool bSpawnedExitPoint;

	// 脱出ポイントＩＤ
	u32 ExitWarpPointId;

	// 初期化されているか？
	bool bInitialized;

};

#endif		// #ifndef __INSTANCEAREA_H__

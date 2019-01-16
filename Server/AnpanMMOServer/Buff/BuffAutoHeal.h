/**
 * @file BuffAutoHeal.h
 * @brief 自動回復バフクラス
 * @author YanaP
 */
#ifndef __BUFFAUTOHEAL_H__
#define __BUFFAUTOHEAL_H__

#include "BuffBase.h"
#include "Master/BuffMaster.h"

/**
 * @class BuffAutoHeal
 * @brief 自動回復バフ
 */
class BuffAutoHeal : public BuffBase
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] Time 継続時間
	 * @param[in] pInCharacter キャラクタ
	 * @param[in] InHealRate 回復レート
	 */
	BuffAutoHeal(u32 Time, CharacterBase *pInCharacter, float InHealRate);

	/**
	 * @brief デストラクタ
	 */
	virtual ~BuffAutoHeal() {}

	/**
	 * @fn virtual u8 GetType() const
	 * @brief タイプを取得
	 * @return タイプ
	 */
	virtual u8 GetType() const { return BuffItem::AUTO_HEAL; }

protected:

	/**
	 * @fn virtual void Update(u8 DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	virtual void Update(u32 DeltaTime);

private:

	// 回復インターバル
	static const u32 HealInterval;

	// 回復レート
	float HealRate;

	// 回復タイマー
	s32 HealTimer;

};

#endif		// #ifndef __BUFFAUTOHEAL_H__

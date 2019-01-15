/**
 * @file DebuffPoison.h
 * @brief 毒デバフクラス
 * @author YanaP
 */
#ifndef __DEBUFFPOISON_H__
#define __DEBUFFPOISON_H__

#include "BuffBase.h"
#include "Master/BuffMaster.h"

/**
 * @class DebuffPoison
 * @brief 毒デバフ
 */
class DebuffPoison : public BuffBase
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] Time 継続時間
	 * @param[in] pInCharacter キャラクタ
	 * @param[in] InDamageRate ダメージレート
	 */
	DebuffPoison(u32 Time, CharacterBase *pInCharacter, float InDamageRate);

	/**
	 * @brief デストラクタ
	 */
	virtual ~DebuffPoison() {}

	/**
	 * @fn virtual u8 GetType() const
	 * @brief タイプを取得
	 * @return タイプ
	 */
	virtual u8 GetType() const { return BuffItem::POISON; }

protected:

	/**
	 * @fn virtual void Update(u32 DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	virtual void Update(u32 DeltaTime);

private:

	// ダメージインターバル
	static const u32 DamageInterval;

	// ダメージレート
	float DamageRate;

	// ダメージタイマー
	s32 DamageTimer;

};

#endif		// #ifndef __DEBUFFPOISON_H__

/**
 * @file BuffSpeedUp.h
 * @brief スピードアップバフクラス
 * @author YanaP
 */
#ifndef __BUFFSPEEDUP_H__
#define __BUFFSPEEDUP_H__

#include "BuffBase.h"
#include "Master/BuffMaster.h"

/**
 * @class BuffSpeedUp
 * @brief スピードアップバフ
 */
class BuffSpeedUp : public BuffBase
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] Time 継続時間
	 * @param[in] pInCharacter キャラクタ
	 * @param[in] InSpeedRate 移動速度倍率
	 */
	BuffSpeedUp(u32 Time, CharacterBase *pInCharacter, float InSpeedRate);

	/**
	 * @brief デストラクタ
	 */
	virtual ~BuffSpeedUp() {}

	/**
	 * @fn virtual u8 GetType() const
	 * @brief タイプを取得
	 * @return タイプ
	 */
	virtual u8 GetType() const { return BuffItem::SPEEDUP; }

private:

	// 移動速度倍率.
	float SpeedRate;

};

#endif			// #ifndef __BUFFSPEEDUP_H__

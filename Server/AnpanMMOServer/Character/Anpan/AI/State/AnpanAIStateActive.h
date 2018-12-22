/**
 * @file AnpanAIStateActive.h
 * @brief アンパンＡＩステート：アクティブ状態
 * @author YanaP
 */
#ifndef __ANPANAISTATEACTIVE_H__
#define __ANPANAISTATEACTIVE_H__

#include "AnpanAIStateBase.h"

class CharacterBase;

/**
 * @class AnpanAIStateActive
 * @brief アンパンＡＩステート：アクティブ状態.
 */
class AnpanAIStateActive : public AnpanAIStateBase
{
	
public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInParent アンパン
	 */
	AnpanAIStateActive(Anpan *pInParent);

	/**
	 * @brief デストラクタ
	 */
	virtual ~AnpanAIStateActive() {}

protected:

	/**
	 * @fn virtual void Update(int DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	virtual void Update(int DeltaTime);

private:

	// 「近づいた」と判定する距離.
	static const float ApproachDist;

	// 攻撃インターバル
	static const int AttackInterval;

	// 現在のターゲット
	weak_ptr<CharacterBase> pCurrentTarget;

	// 攻撃タイマー
	int AttackTimer;


	// 回転を更新.
	void UpdateRotate();

	// 移動を更新.
	void UpdateMove();

	// 攻撃を更新.
	void UpdateAttack(int DeltaTime);

	// ターゲットの方向を向く。
	void RotateToTarget();

	// ターゲットに向かって移動する。
	void MoveToTarget();

	// 接近しているか？
	bool IsApproached();

};


#endif		// #ifndef __ANPANAISTATEACTIVE_H__

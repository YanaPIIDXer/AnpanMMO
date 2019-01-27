/**
 * @file AnpanAIStateActive.h
 * @brief アンパンＡＩステート：アクティブ状態
 * @author YanaP
 */
#ifndef __ANPANAISTATEACTIVE_H__
#define __ANPANAISTATEACTIVE_H__

#include "AnpanAIStateBase.h"
#include "WeakPtrDefine.h"

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

	// 現在の行動
	AIActionPtr pCurrentAction;

	// 現在のターゲット
	CharacterPtr pCurrentTarget;

	// スキルターゲット
	CharacterPtr pSkillTarget;

	// 待機タイマー
	int WaitTimer;

	// アクションが初期化されているか？
	bool bInitializedAction;

	// スキル発動距離.
	float SkillDistance;


	// ターゲットの方向を向く。
	void RotateToTarget();

	// ターゲットに向かって移動する。
	void MoveToTarget();

	// 接近しているか？
	bool IsApproached();

	// ターゲットから距離を取る。
	void KeepDistanceToTarget();

	// ターゲットから距離を取ったか？
	bool IsKeepedDistanceToTarget();

	// スキル使用.
	void UseSkill();

	// 次のアクションに変更.
	void ChangeToNextAction();

	// アクションの初期化.
	void InitializeAction();

};


#endif		// #ifndef __ANPANAISTATEACTIVE_H__

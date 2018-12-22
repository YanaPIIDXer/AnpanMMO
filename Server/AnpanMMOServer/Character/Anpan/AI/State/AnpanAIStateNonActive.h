/**
 * @file AnpanAIStateNonActive.h
 * @brief アンパンＡＩステート：ノンアクティブ状態
 * @author YanaP
 */
#ifndef __ANPANAISTATENONACTIVE_H__
#define __ANPANAISTATENONACTIVE_H__

#include "AnpanAIStateBase.h"

/**
 * @class AnpanAIStateNonActive
 * @brief アンパンＡＩステート：ノンアクティブ状態
 */
class AnpanAIStateNonActive : public AnpanAIStateBase
{

public:
	
	/**
	 * @brief コンストラクタ
	 * @param[in] pInParent アンパン
	 */
	AnpanAIStateNonActive(Anpan *pInParent);

	/**
	 * @brief デストラクタ
	 */
	virtual ~AnpanAIStateNonActive() {}

	/**
	 * @fn virtual void OnDamaged()
	 * @brief ダメージを受けた
	 */
	virtual void OnDamaged();

protected:

	/**
	 * @fn virtual void Update(int DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	virtual void Update(int DeltaTime);

private:

	// 内部ステート
	enum EState
	{
		// 初期状態.
		None,

		// 停止中.
		Stopping,

		// 回転中.
		Rotating,

		// 移動中.
		Moving,
	};

	// 現在の内部ステート
	EState CurrentState;

	// ステート時間.
	int StateTime;


	// 停止状態の更新.
	void UpdateStopping();

	// 回転状態の更新.
	void UpdateRotating();

	// 移動状態の更新.
	void UpdateMoving();

};

#endif		// #ifndef __ANPANAISTATENONACTIVE_H__

#ifndef __ANPANAISTATENONACTIVE_H__
#define __ANPANAISTATENONACTIVE_H__

#include "AnpanAIStateBase.h"

/**
 * アンパンＡＩステート：ノンアクティブ状態.
 */
class AnpanAIStateNonActive : public AnpanAIStateBase
{

public:
	
	// コンストラクタ
	AnpanAIStateNonActive(Anpan *pInParent);

	// デストラクタ
	virtual ~AnpanAIStateNonActive() {}

	// ダメージを受けた。
	virtual void OnDamaged();

protected:

	// 更新処理.
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

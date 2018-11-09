#ifndef __ANPANAISTATEACTIVE_H__
#define __ANPANAISTATEACTIVE_H__

#include "AnpanAIStateBase.h"

class CharacterBase;

/**
 * アンパンＡＩステート：アクティブ状態.
 */
class AnpanAIStateActive : public AnpanAIStateBase
{
	
public:

	// コンストラクタ
	AnpanAIStateActive(Anpan *pInParent);

	// デストラクタ
	virtual ~AnpanAIStateActive() {}

protected:

	// 更新.
	virtual void Update(int DeltaTime);

private:

	// 内部State
	enum EState
	{
		// 回転中.
		Rotating,

		// 移動中.
		Moving,
	};

	// 現在のターゲット
	weak_ptr<CharacterBase> pCurrentTarget;

	// 行動タイマー
	int ActionTimer;

	// 内部State
	EState CurrentState;
	
	// ターゲットの以前の座標.
	Vector2D PrevTargetPos;

	// 回転を更新.
	void UpdateRotate();

	// 移動を更新.
	void UpdateMove();

};


#endif		// #ifndef __ANPANAISTATEACTIVE_H__

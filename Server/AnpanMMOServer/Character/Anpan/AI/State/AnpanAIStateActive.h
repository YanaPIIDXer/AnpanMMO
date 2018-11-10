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

	// 「近づいた」と判定する距離.
	static const float ApproachDist;

	// 現在のターゲット
	weak_ptr<CharacterBase> pCurrentTarget;


	// 回転を更新.
	void UpdateRotate();

	// 移動を更新.
	void UpdateMove();

	// ターゲットの方向を向く。
	void RotateToTarget();

	// ターゲットに向かって移動する。
	void MoveToTarget();

	// 接近しているか？
	bool IsApproached();

};


#endif		// #ifndef __ANPANAISTATEACTIVE_H__

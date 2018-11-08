#ifndef __ANPANAISTATEBASE_H__
#define __ANPANAISTATEBASE_H__

#include "Math/Vector2D.h"
#include "Math/Rotation.h"

class Anpan;
class AnpanAI;

/**
 * アンパンＡＩステート基底クラス
 */
class AnpanAIStateBase
{

public:

	// コンストラクタ
	AnpanAIStateBase(Anpan *pInParent);

	// デストラクタ
	virtual ~AnpanAIStateBase() = 0;

	// 毎フレームの処理.
	void Poll(int DeltaTime);

	// AIを設定.
	void SetAI(AnpanAI *pInAI) { pAI = pInAI; }

	// ダメージを受けた。
	virtual void OnDamaged() {}

protected:

	// 更新処理.
	virtual void Update(int DeltaTime) {}

	// 親を取得.
	Anpan *GetParent() { return pParent; }

	// AIを取得.
	AnpanAI *GetAI() { return pAI; }

	// 移動を設定.
	void SetMove(const Vector2D &InMoveTarget, int Time);

	// 回転を設定.
	void SetRotate(const Rotation &InRotateTarget, int Time);

	// 停止.
	void Stop();

private:

	// 親.
	Anpan *pParent;

	// AI
	AnpanAI *pAI;

	// 以前の座標.
	Vector2D PrevPos;

	// 移動先.
	Vector2D MoveTarget;

	// 移動時間.
	int MoveTime;

	// 回転開始時間.
	int MoveStartTime;

	// 以前の回転.
	Rotation PrevRotate;

	// 回転先.
	Rotation RotateTarget;

	// 回転時間.
	int RotateTime;

	// 回転開始時間.
	int RotateStartTime;


	// 移動更新.
	void UpdateMove(int DeltaTime);

	// 回転更新.
	void UpdateRotate(int DeltaTime);

};

#endif		// #ifndef __ANPANAISTATEBASE_H__

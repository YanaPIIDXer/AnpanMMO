/**
 * @file AnpanAIStateNonActive.h
 * @brief アンパンＡＩステート基底クラス
 * @author YanaP
 */
#ifndef __ANPANAISTATEBASE_H__
#define __ANPANAISTATEBASE_H__

#include "Math/Vector3D.h"
#include "Math/Rotation.h"

class Anpan;
class AnpanAI;

/**
 * @class AnpanAIStateBase
 * @brief アンパンＡＩステート基底クラス
 */
class AnpanAIStateBase
{

public:

	/** 
	 * @brief コンストラクタ
	 * @param[in] pInParent アンパン
	 */
	AnpanAIStateBase(Anpan *pInParent);

	/**
	 * @brief デストラクタ
	 */
	virtual ~AnpanAIStateBase() = 0;

	/**
	 * @fn void Poll(int DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	void Poll(int DeltaTime);

	/**
	 * @fn void SetAI(AnpanAI *pInAI)
	 * @brief AIを設定
	 * @param[in] pInAI AI
	 */
	void SetAI(AnpanAI *pInAI) { pAI = pInAI; }

	/**
	 * @fn virtual void OnDamaged()
	 * @brief ダメージを受けた
	 */
	virtual void OnDamaged() {}

protected:

	/**
	 * @fn virtual void Update(int DeltaTime)
	 * @brief 更新処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	virtual void Update(int DeltaTime) {}

	/**
	 * @fn Anpan *GetParent()
	 * @brief 親を取得
	 * @return アンパン
	 */
	Anpan *GetParent() { return pParent; }

	/**
	 * @fn AnpanAI *GetAI()
	 * @brief AIを取得
	 * @return AI
	 */
	AnpanAI *GetAI() { return pAI; }

	/**
	 * @fn void SetMove(const Vector3D &InMoveTarget, int Time)
	 * @brief 移動を設定
	 * @param[in] InMoveTarget 移動先
	 * @param[in] Time 移動時間
	 */
	void SetMove(const Vector3D &InMoveTarget, int Time);

	/**
	 * @fn void SetRotate(const Rotation &InRotateTarget, int Time)
	 * @brief 回転を設定
	 * @param[in] InRotateTarget 回転
	 * @param[in] Time 回転時間
	 */
	void SetRotate(const Rotation &InRotateTarget, int Time);

	/**
	 * @fn void Stop()
	 * @brief 停止
	 */
	void Stop();

	/**
	 * @fn bool IsMoving() const
	 * @brief 移動中？
	 * @return 移動中ならtrueを返す。
	 */
	bool IsMoving() const { return (MoveTime > 0); }

	/**
	 * @fn bool IsRotating() const
	 * @brief 回転中？
	 * @return 回転中ならtrueを返す。
	 */
	bool IsRotating() const { return (RotateTime > 0); }

private:

	// 親.
	Anpan *pParent;

	// AI
	AnpanAI *pAI;

	// 以前の座標.
	Vector3D PrevPos;

	// 移動先.
	Vector3D MoveTarget;

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

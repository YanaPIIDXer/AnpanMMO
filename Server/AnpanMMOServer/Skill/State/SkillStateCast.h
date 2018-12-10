#ifndef __SKILLSTATECAST_H__
#define __SKILLSTATECAST_H__

#include "SkillStateBase.h"

/**
 * スキルステート：キャスト中.
 */
class SkillStateCast : public SkillStateBase
{

public:

	// コンストラクタ
	SkillStateCast(SkillControl *pInControl);

	// デストラクタ
	virtual ~SkillStateCast() {}

	// 毎フレームの処理.
	virtual void Poll(s32 DeltaTime);

	// ステートタイプを取得.
	virtual ESkillStateType GetStateType() { return Cast; }

private:

	// キャスト時間.
	s32 CastTime;

};

#endif		// #ifndef __SKILLSTATECAST_H__

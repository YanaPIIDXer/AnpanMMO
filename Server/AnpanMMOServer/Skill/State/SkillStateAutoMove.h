#ifndef __SKILLSTATEAUTOMOVE_H__
#define __SKILLSTATEAUTOMOVE_H__

#include "SkillStateBase.h"

class CharacterBase;

/**
 * スキルステート：オート移動.
 */
class SkillStateAutoMove : public SkillStateBase
{

public:

	// コンストラクタ
	SkillStateAutoMove(SkillControl *pInContril);

	// デストラクタ
	virtual ~SkillStateAutoMove() {}

	// 毎フレームの処理.
	virtual void Poll(s32 DeltaTime);

private:

	// 制限時間.
	static const s32 AutoMoveLimitTime;

	// 経過時間.
	s32 ElapsedTime;

	// 発動距離.
	s32 SkillDistance;

	// 所有者.
	CharacterBase *pOwner;

	// ターゲット.
	CharacterBase *pTarget;

};

#endif		// #ifndef __SKILLSTATEAUTOMOVE_H__

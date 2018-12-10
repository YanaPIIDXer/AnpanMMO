#ifndef __SKILLCONTROL_H__
#define __SKILLCONTROL_H__

class SkillStateBase;
class CharacterBase;

/**
 * スキル制御.
 */
class SkillControl
{

public:

	// コンストラクタ
	SkillControl(CharacterBase *pInOwner);

	// デストラクタ
	~SkillControl() {}

	// 毎フレームの処理.
	void Poll(s32 DeltaTime);

	// 使用.
	void Use(u32 InSkillId, CharacterBase *pInTarget);

	// 所有者を取得.
	CharacterBase *GetOwner() const { return pOwner; }

	// スキルＩＤを取得
	u32 GetSkillId() const { return SkillId; }

	// ターゲットを取得。
	CharacterBase *GetTarget() const { return pTarget; }

private:

	// State
	SkillStateBase *pState;

	// 所有者.
	CharacterBase *pOwner;

	// ターゲット.
	CharacterBase *pTarget;

	// スキルＩＤ
	u32 SkillId;

};

#endif		// #ifndef __SKILLCONTROL_H__
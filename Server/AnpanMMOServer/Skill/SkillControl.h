#ifndef __SKILLCONTROL_H__
#define __SKILLCONTROL_H__

class SkillStateBase;
class CharacterBase;

#include <boost/function.hpp>

/**
 * スキル制御.
 */
class SkillControl
{

private:		// 別名定義.

	typedef boost::function<void(u8)> OnCancelFunction;

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

	// ステート変更.
	void ChangeState(SkillStateBase *pNewState);

	// キャストが完了した。
	void CastFinished();

	// キャンセル
	void Cancel(u8 Reason);

	// 発動.
	void Activate();

	// 何かやっているか？
	bool IsActive() const;

	// キャンセル時に実行される関数を設定.
	void SetOnCancelFunction(const OnCancelFunction &Func) { OnCancelFunc = Func; }

private:

	// State
	SkillStateBase *pState;

	// 前のState
	SkillStateBase *pPrevState;

	// 所有者.
	CharacterBase *pOwner;

	// ターゲット.
	CharacterBase *pTarget;

	// スキルＩＤ
	u32 SkillId;

	// キャンセル時に実行される関数.
	OnCancelFunction OnCancelFunc;

};

#endif		// #ifndef __SKILLCONTROL_H__

#ifndef __SKILLCONTROL_H__
#define __SKILLCONTROL_H__

#include <boost/function.hpp>
#include "WeakPtrDefine.h"

class SkillStateBase;

/**
 * スキル制御.
 */
class SkillControl
{

private:		// 別名定義.

	typedef boost::function<void(u8)> OnCancelFunction;

	typedef boost::function<void(u32)> OnUsedItemFunction;

	typedef boost::function<void(CharacterBase *)> OnKilledFunction;

public:

	// コンストラクタ
	SkillControl(CharacterBase *pInOwner);

	// デストラクタ
	~SkillControl();

	// 毎フレームの処理.
	void Poll(s32 DeltaTime);

	// 使用.
	void Use(u32 InSkillId, CharacterPtr pInTarget);

	// アイテム使用.
	void UseItem(u32 InItemId, CharacterPtr pInTarget);

	// 所有者を取得.
	CharacterBase *GetOwner() const { return pOwner; }

	// スキルＩＤを取得
	u32 GetSkillId() const { return SkillId; }

	// ターゲットを取得。
	CharacterPtr GetTarget() const { return pTarget; }

	// キャストが完了した。
	void CastFinished();

	// キャンセル
	void Cancel(u8 Reason);

	// 発動.
	void Activate();

	// 何かやっているか？
	bool IsActive() const;

	// キャスト中か？
	bool IsCasting() const;

	// キャンセル時に実行される関数を設定.
	void SetOnCancelFunction(const OnCancelFunction &Func) { OnCancelFunc = Func; }

	// アイテム使用後に実行される関数を設定.
	void SetOnUsedItemFunction(const OnUsedItemFunction &Func) { OnUsedItemFunc = Func; }

	// 殺害後に実行される関数を設定.
	void SetOnKilledFunction(const OnKilledFunction &Func) { OnKilledFunc = Func; }

private:

	// State
	SkillStateBase *pState;

	// 前のState
	SkillStateBase *pPrevState;

	// 所有者.
	CharacterBase *pOwner;

	// ターゲット.
	CharacterPtr pTarget;

	// スキルＩＤ
	u32 SkillId;

	// アイテムＩＤ
	u32 ItemId;

	// キャンセル時に実行される関数.
	OnCancelFunction OnCancelFunc;

	// アイテム使用後に実行される関数.
	OnUsedItemFunction OnUsedItemFunc;

	// 殺害後に実行される関数.
	OnKilledFunction OnKilledFunc;

	// ステート変更.
	void ChangeState(SkillStateBase *pNewState);

};

#endif		// #ifndef __SKILLCONTROL_H__

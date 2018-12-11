// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Master/SkillMaster.h"

class SkillStateBase;
class ACharacterBase;

/**
 * スキル制御クラス
 */
class ANPANMMO_API SkillControl
{

public:

	// コンストラクタ
	SkillControl();

	// デストラクタ
	~SkillControl();

	// 毎フレームの処理.
	void Poll();

	// 所有者を設定.
	void SetOwner(ACharacterBase *pInOwner) { pOwner = pInOwner; }
	
	// スキル使用.
	void UseSkill(uint32 SkillId, ACharacterBase *pInTarget);

	// キャストが完了した.
	void OnCastFinished();

	// スキルが発動した。
	void OnActivate();

	// 所有者を取得.
	TWeakObjectPtr<ACharacterBase> GetOwner() const { return pOwner; }

	// ターゲットを取得.
	TWeakObjectPtr<ACharacterBase> GetTarget() const { return pTarget; }

	// スキルデータを取得.
	const SkillItem &GetSkillData() const { return SkillData; }

	// 何かしているか？
	bool IsActive() const;

private:

	// 現在のState
	SkillStateBase *pState;

	// 前のState
	SkillStateBase *pPrevState;

	// 所有者.
	TWeakObjectPtr<ACharacterBase> pOwner;

	// ターゲット
	TWeakObjectPtr<ACharacterBase> pTarget;

	// スキルデータ
	SkillItem SkillData;


	// State切り替え
	void ChangeState(SkillStateBase *pNewState);

};

// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class SkillControl;

// スキルステートタイプ
enum class ESkillStateType : uint8
{
	// 何もしていない
	Nutral,

	// キャスト中.
	Cast,

	// オート移動中.
	AutoMode,
};

/**
 * スキルステート基底クラス
 */
class ANPANMMO_API SkillStateBase
{

public:

	// コンストラクタ
	SkillStateBase(SkillControl *pInControl);

	// デストラクタ
	virtual ~SkillStateBase() {}

	// State開始時の処理.
	virtual void BeginState() {}

	// 毎フレームの処理.
	virtual void Poll() {}

	// ステートタイプを取得.
	virtual ESkillStateType GetStateType() = 0;

protected:

	// スキル制御オブジェクトを取得.
	SkillControl *GetControl() { return pControl; }

private:

	// スキル制御オブジェクト
	SkillControl *pControl;

};

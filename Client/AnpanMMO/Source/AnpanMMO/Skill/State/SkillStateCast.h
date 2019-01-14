// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkillStateBase.h"

/**
 * スキルステート：キャスト中.
 */
class ANPANMMO_API SkillStateCast : public SkillStateBase
{
public:

	// コンストラクタ
	SkillStateCast(SkillControl *pInControl);

	// デストラクタ
	virtual ~SkillStateCast() {}

	// ステートタイプを取得.
	virtual ESkillStateType GetStateType() override { return ESkillStateType::Cast; }

private:

};

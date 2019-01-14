// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkillStateBase.h"

/**
 * スキルステート：何もしていない。
 */
class ANPANMMO_API SkillStateNutral : public SkillStateBase
{

public:

	// コンストラクタ
	SkillStateNutral(SkillControl *pInControl);

	// デストラクタ
	virtual ~SkillStateNutral() {}

	// ステートタイプを取得.
	virtual ESkillStateType GetStateType() override { return ESkillStateType::Nutral; }

private:

};

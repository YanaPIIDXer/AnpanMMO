// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkillStateBase.h"

class ACharacterBase;

/**
 * スキルステート：オート移動中.
 */
class ANPANMMO_API SkillStateAutoMove : public SkillStateBase
{

public:

	// コンストラクタ
	SkillStateAutoMove(SkillControl *pInControl);

	// デストラクタ
	virtual ~SkillStateAutoMove() {}

	// State開始時の処理.
	virtual void BeginState() override;

	// 毎フレームの処理.
	virtual void Poll() override;

	// ステートタイプを取得.
	virtual ESkillStateType GetStateType() override { return ESkillStateType::AutoMode; }

private:

	// 所有者.
	TWeakObjectPtr<ACharacterBase> pOwner;

	// ターゲット
	TWeakObjectPtr<ACharacterBase> pTarget;

	// 距離.
	float Distance;

	// 移動パケットを送ったか？
	bool bSendMovePacket;

};

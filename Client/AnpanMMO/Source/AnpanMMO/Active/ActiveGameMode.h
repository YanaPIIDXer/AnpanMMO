// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include "Character/Anpan/AnpanManager.h"
#include "ActiveGameMode.generated.h"

/**
 * ゲーム中GameMode
 */
UCLASS()
class ANPANMMO_API AActiveGameMode : public AMMOGameModeBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	AActiveGameMode(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AActiveGameMode() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

protected:

private:

	// アンパン管理.
	AnpanManager AnpanMgr;

};

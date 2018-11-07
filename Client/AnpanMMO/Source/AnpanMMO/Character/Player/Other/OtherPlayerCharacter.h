// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/Player/PlayerCharacterBase.h"
#include "OtherPlayerCharacter.generated.h"

class AOtherPlayerController;

/**
 * 他人のPlayerCharacter
 */
UCLASS()
class ANPANMMO_API AOtherPlayerCharacter : public APlayerCharacterBase
{

	GENERATED_BODY()
	
public:

	// Spawn
	static AOtherPlayerCharacter *Spawn(UWorld *pWorld, const FVector &Position, const FRotator &Rotation);

	// コンストラクタ
	AOtherPlayerCharacter(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AOtherPlayerCharacter() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// コントローラと紐付けられた。
	virtual void PossessedBy(AController *NewController) override;

	// 移動.
	virtual void Move(float X, float Y, float Rotation) override;

	// 移動ベクトルの取得.
	virtual FVector GetMoveVector() const override;

protected:

private:
	
	// コントローラ
	TWeakObjectPtr<AOtherPlayerController> pController;
	
};

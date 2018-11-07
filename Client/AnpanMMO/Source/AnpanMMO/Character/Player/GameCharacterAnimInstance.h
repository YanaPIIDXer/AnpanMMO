// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameCharacterAnimInstance.generated.h"

class APlayerCharacterBase;

/**
 * GameCharacter用AnimInstance
 */
UCLASS()
class ANPANMMO_API UGameCharacterAnimInstance : public UAnimInstance
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	UGameCharacterAnimInstance(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UGameCharacterAnimInstance() {}

	// 開始時の処理.
	virtual void NativeInitializeAnimation() override;

	// 毎フレームの処理.
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:

	// 移動ベクトル
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	FVector MoveVector;

private:

	// キャラクター
	TWeakObjectPtr<APlayerCharacterBase> pCharacter;

};

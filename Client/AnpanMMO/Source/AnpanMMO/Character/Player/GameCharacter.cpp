// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"

// コンストラクタ
AGameCharacter::AGameCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	pMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
}

// 開始時の処理.
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// 毎フレームの処理.
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

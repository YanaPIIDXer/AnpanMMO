// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacter.h"
#include "GameFramework/FloatingPawnMovement.h"

// �R���X�g���N�^
AGameCharacter::AGameCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	pMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
}

// �J�n���̏���.
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// ���t���[���̏���.
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

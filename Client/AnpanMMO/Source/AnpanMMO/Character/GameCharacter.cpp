// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "GameCharacter.h"

// �R���X�g���N�^
AGameCharacter::AGameCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
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

// InputComponent�̃Z�b�g�A�b�v
void AGameCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

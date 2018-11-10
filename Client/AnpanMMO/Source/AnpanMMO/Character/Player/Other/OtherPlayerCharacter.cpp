// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "OtherPlayerCharacter.h"
#include "OtherPlayerController.h"
#include "Util.h"

const TCHAR *AOtherPlayerCharacter::AssetPath = TEXT("/Game/Blueprints/System/Active/OtherPlayerCharacter.OtherPlayerCharacter");

// Spawn
AOtherPlayerCharacter *AOtherPlayerCharacter::Spawn(UWorld *pWorld, const FVector &Position, const FRotator &Rotation, int32 Hp, int32 MaxHp)
{
	auto pCharacter = Util::SpawnFromBlueprint<AOtherPlayerCharacter>(pWorld, AssetPath, Position, Rotation);
	pCharacter->Initialize(Hp, MaxHp);

	return pCharacter;
}

// �R���X�g���N�^
AOtherPlayerCharacter::AOtherPlayerCharacter(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
	AIControllerClass = AOtherPlayerController::StaticClass();
}

// �J�n���̏���.
void AOtherPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// ���R���g���[���𐶐�����ɂ̓R�C�c���Ăяo���K�v������炵���B
	SpawnDefaultController();
}

// �R���g���[���ƕR�t����ꂽ�B
void AOtherPlayerCharacter::PossessedBy(AController *NewController)
{
	Super::PossessedBy(NewController);

	pController = Cast<AOtherPlayerController>(NewController);
	check(pController != nullptr);
}

// �ړ�.
void AOtherPlayerCharacter::Move(float X, float Y, float Rotation)
{
	pController->Move(X, Y, Rotation);
}

// �ړ��x�N�g���̎擾.
FVector AOtherPlayerCharacter::GetMoveVector() const
{
	if (pController == nullptr) { return FVector::ZeroVector; }
	return pController->GetMoveVector();
}

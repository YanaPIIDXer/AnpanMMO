// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/Player/PlayerCharacterBase.h"
#include "OtherPlayerCharacter.generated.h"

class AOtherPlayerController;

/**
 * ���l��PlayerCharacter
 */
UCLASS()
class ANPANMMO_API AOtherPlayerCharacter : public APlayerCharacterBase
{

	GENERATED_BODY()
	
public:

	// Spawn
	static AOtherPlayerCharacter *Spawn(UWorld *pWorld, uint32 Uuid, const FVector &Position, const FRotator &Rotation, int32 Hp, int32 MaxHp, const FString &CharacterName, uint8 Job);

	// �R���X�g���N�^
	AOtherPlayerCharacter(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AOtherPlayerCharacter() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// �R���g���[���ƕR�t����ꂽ�B
	virtual void PossessedBy(AController *NewController) override;

	// �ړ�.
	virtual void Move(float X, float Y, float Z, float Rotation) override;

	// �ړ��x�N�g���̎擾.
	virtual FVector GetMoveVector() const override;

	// UUID���擾.
	virtual uint32 GetUuid() const override { return Uuid; }

	// �L�����N�^�����擾.
	virtual FString GetCharacterName() const override { return CharacterName; }

	// �L�����N�^�^�C�v���擾.
	virtual ECharacterType GetCharacterType() const override { return ECharacterType::Other; }

private:

	// Blueprint�̃A�Z�b�g�p�X
	static const TCHAR *AssetPath;
	
	// �R���g���[��
	TWeakObjectPtr<AOtherPlayerController> pController;

	// UUID
	uint32 Uuid;

	// �W���u
	uint8 Job;

	// �L�����N�^��.
	FString CharacterName;
	
};

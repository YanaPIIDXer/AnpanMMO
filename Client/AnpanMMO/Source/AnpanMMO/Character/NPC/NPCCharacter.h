// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "NPCCharacter.generated.h"

struct NPCItem;

/**
 * NPC�L�����N�^
 */
UCLASS()
class ANPANMMO_API ANPCCharacter : public ACharacterBase
{

	GENERATED_BODY()

public:

	// Spawn
	static ANPCCharacter *Spawn(UWorld *pWorld, const NPCItem *pItem);

	// �R���X�g���N�^
	ANPCCharacter(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ANPCCharacter() {}

	// ID�擾.
	uint32 GetId() const { return Id; }

	// �L�����N�^�^�C�v���擾.
	virtual ECharacterType GetCharacterType() const override { return ECharacterType::NPC; }

	// �����̔������擾.
	float GetHalfHeight() const override { return HalfHeight; }

private:
	
	// ID
	uint32 Id;

	// �����̍���
	float HalfHeight;


	// ���b�V���̃Z�b�g�A�b�v
	void SetupMesh(USkeletalMesh *pMesh);

};

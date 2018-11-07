// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "PlayerCharacterBase.generated.h"

/**
 * �v���C���[�L�������N���X
 */
UCLASS()
class ANPANMMO_API APlayerCharacterBase : public ACharacterBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	APlayerCharacterBase(const FObjectInitializer &ObjectInitializer);
	
	// �f�X�g���N�^
	virtual ~APlayerCharacterBase() {}

protected:

	// MeshComponent�擾.
	USkeletalMeshComponent *GetMeshComponent() const { return pMeshComponent; }

private:

	// ���b�V���p�X
	static const TCHAR *MeshPath;

	// MeshComponent
	UPROPERTY()
	USkeletalMeshComponent *pMeshComponent;

};

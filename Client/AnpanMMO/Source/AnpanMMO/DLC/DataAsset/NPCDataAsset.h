// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NPCDataAsset.generated.h"

class USkeletalMesh;

/**
 * NPC���\�[�X��DataAsset
 */
UCLASS()
class ANPANMMO_API UNPCDataAsset : public UDataAsset
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UNPCDataAsset(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UNPCDataAsset() {}

	// �擾.
	USkeletalMesh *Get(int32 Index);

private:

	// �A�Z�b�g���X�g
	UPROPERTY(EditAnywhere)
	TArray<TAssetPtr<USkeletalMesh>> Assets;
	
};

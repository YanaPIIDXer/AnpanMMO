// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LevelStreamingDynamic.h"
#include "LevelManager.generated.h"

DECLARE_DELEGATE(FOnLevelLoadFinished);

/**
 * ���x���Ǘ�.
 */
UCLASS()
class ANPANMMO_API ULevelManager : public UObject
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	ULevelManager(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ULevelManager() {}

	// ���[���h��ݒ�
	void SetWorld(UWorld *pInWorld) { pWorld = pInWorld; }

	// ���t���[���̏���.
	void Poll();

	// ���[�h
	void Load(const FString &LevelPath);


	// ���x�����[�h�����������B
	FOnLevelLoadFinished OnLevelLoadFinished;

private:

	// World
	TWeakObjectPtr<UWorld> pWorld;
	
	// �X�g���[�~���O���̃��x��
	UPROPERTY()
	ULevelStreamingDynamic *pStreamingLevel;

	// ���[�h�������������H
	bool bIsLoaded;

};

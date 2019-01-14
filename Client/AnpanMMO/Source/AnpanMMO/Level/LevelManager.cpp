// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "LevelManager.h"
#include "Engine/World.h"

// �R���X�g���N�^
ULevelManager::ULevelManager(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pStreamingLevel(nullptr)
	, bIsLoaded(false)
{
}

// ���t���[���̏���.
void ULevelManager::Poll()
{
	if (pStreamingLevel == nullptr) { return; }
	if (!bIsLoaded && pStreamingLevel->GetLoadedLevel() != nullptr)
	{
		OnLevelLoadFinished.ExecuteIfBound();
		bIsLoaded = true;
	}
}

// ���[�h
void ULevelManager::Load(const FString &LevelPath)
{
	if (pStreamingLevel != nullptr)
	{
		pStreamingLevel->SetShouldBeVisible(false);
		pStreamingLevel->SetShouldBeLoaded(false);
		pStreamingLevel = nullptr;
	}
	bool bSuccess = false;
	pStreamingLevel = ULevelStreamingDynamic::LoadLevelInstance(this, LevelPath, FVector::ZeroVector, FRotator::ZeroRotator, bSuccess);
	if (!bSuccess)
	{
		UE_LOG(LogTemp, Log, TEXT("Level %s Load Failed..."), *LevelPath);
		return;
	}

	pStreamingLevel->SetShouldBeLoaded(true);
	pStreamingLevel->SetShouldBeVisible(true);
	pStreamingLevel->bShouldBlockOnLoad = false;
	pStreamingLevel->bInitiallyLoaded = true;
	pStreamingLevel->bInitiallyVisible = true;
	pStreamingLevel->PackageNameToLoad = *LevelPath;
	
	bIsLoaded = false;

	// �������Ȃ��B
	//pStreamingLevel->OnLevelLoaded.AddDynamic(this, &ULevelManager::OnLevelLoaded);

	// ������ULevelStreamingDynamic::LoadLevelInstance�֐����Ăяo���֐����Ŏ��s����Ă���炵���B
	//pWorld->AddStreamingLevel(pStreamingLevel);
}

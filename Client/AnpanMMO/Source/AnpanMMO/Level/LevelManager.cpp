// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "LevelManager.h"
#include "Engine/World.h"

// コンストラクタ
ULevelManager::ULevelManager(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pStreamingLevel(nullptr)
	, bIsLoaded(false)
{
}

// 毎フレームの処理.
void ULevelManager::Poll()
{
	if (pStreamingLevel == nullptr) { return; }
	if (!bIsLoaded && pStreamingLevel->GetLoadedLevel() != nullptr)
	{
		OnLevelLoadFinished.ExecuteIfBound();
		bIsLoaded = true;
	}
}

// ロード
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

	// ↓動かない。
	//pStreamingLevel->OnLevelLoaded.AddDynamic(this, &ULevelManager::OnLevelLoaded);

	// ↓実はULevelStreamingDynamic::LoadLevelInstance関数が呼び出す関数内で実行されているらしい。
	//pWorld->AddStreamingLevel(pStreamingLevel);
}

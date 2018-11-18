// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "LevelManager.h"
#include "Engine/World.h"

// コンストラクタ
ULevelManager::ULevelManager(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pWorld(nullptr)
	, pLevelStreaming(nullptr)
	, bIsLoaded(false)
{
}

// 毎フレームの処理.
void ULevelManager::Poll()
{
	if (pLevelStreaming == nullptr) { return; }
	if (!bIsLoaded && pLevelStreaming->GetLoadedLevel() != nullptr)
	{
		OnLevelLoadFinished.ExecuteIfBound();
		bIsLoaded = true;
	}
}

// ロード
void ULevelManager::Load(const FString &LevelPath)
{
	if (pLevelStreaming != nullptr)
	{
		pWorld->RemoveStreamingLevel(pLevelStreaming);
		pLevelStreaming = nullptr;
	}
	bool bSuccess = false;
	pLevelStreaming = ULevelStreamingDynamic::LoadLevelInstance(this, LevelPath, FVector::ZeroVector, FRotator::ZeroRotator, bSuccess);
	if (!bSuccess)
	{
		UE_LOG(LogTemp, Log, TEXT("Level %s Load Failed..."), *LevelPath);
		return;
	}
	pLevelStreaming->SetShouldBeLoaded(true);
	pLevelStreaming->SetShouldBeVisible(true);
	pLevelStreaming->bShouldBlockOnLoad = true;
	pLevelStreaming->bInitiallyLoaded = true;
	pLevelStreaming->bInitiallyVisible = true;
	pLevelStreaming->PackageNameToLoad = *LevelPath;

	bIsLoaded = false;

	// ↓動かない。
	//pLevelStreaming->OnLevelLoaded.AddDynamic(this, &ULevelManager::OnLevelLoaded);
	pWorld->AddStreamingLevel(pLevelStreaming);
}

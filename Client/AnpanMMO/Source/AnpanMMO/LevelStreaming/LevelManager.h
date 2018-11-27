// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LevelStreamingDynamic.h"
#include "LevelManager.generated.h"

DECLARE_DELEGATE(FOnLevelLoadFinished);

/**
 * レベル管理.
 */
UCLASS()
class ANPANMMO_API ULevelManager : public UObject
{

	GENERATED_BODY()

public:

	// コンストラクタ
	ULevelManager(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ULevelManager() {}

	// ワールドを設定
	void SetWorld(UWorld *pInWorld) { pWorld = pInWorld; }

	// 毎フレームの処理.
	void Poll();

	// ロード
	void Load(const FString &LevelPath);


	// レベルロードが完了した。
	FOnLevelLoadFinished OnLevelLoadFinished;

private:

	// World
	TWeakObjectPtr<UWorld> pWorld;
	
	// ストリーミング中のレベル
	UPROPERTY()
	ULevelStreamingDynamic *pStreamingLevel;

	// ロードが完了したか？
	bool bIsLoaded;

};

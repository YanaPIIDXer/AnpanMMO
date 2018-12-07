// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NPCDataAsset.generated.h"

class USkeletalMesh;

/**
 * NPCリソースのDataAsset
 */
UCLASS()
class ANPANMMO_API UNPCDataAsset : public UDataAsset
{

	GENERATED_BODY()

public:

	// コンストラクタ
	UNPCDataAsset(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UNPCDataAsset() {}

	// 取得.
	USkeletalMesh *Get(int32 Index);

private:

	// アセットリスト
	UPROPERTY(EditAnywhere)
	TArray<TAssetPtr<USkeletalMesh>> Assets;
	
};

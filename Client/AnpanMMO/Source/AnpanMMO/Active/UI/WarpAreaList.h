// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WarpAreaList.generated.h"

/**
 * ワープエリアリスト
 */
UCLASS()
class ANPANMMO_API UWarpAreaList : public UUserWidget
{

	GENERATED_BODY()

public:

	// 生成.
	static void Create(UObject *pOuter, uint32 Id);

	// コンストラクタ
	UWarpAreaList(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UWarpAreaList() {}

	// 生成時の処理.
	virtual void NativeConstruct() override;

	// 破棄時の処理.
	virtual void NativeDestruct() override;

protected:

	// アイテム追加。
	UFUNCTION(BlueprintNativeEvent, Category = "WarpAreaList")
	void AddItem(int32 Id, const FString &Name);
	void AddItem_Implementation(int32 Id, const FString &Name) {}

private:

	// アセットのパス
	static const TCHAR *AssetPath;

	// ID
	uint32 Id;
	
};

// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "WarpAreaList.generated.h"

/**
 * ワープエリアリスト
 */
UCLASS()
class ANPANMMO_API UWarpAreaList : public ULayeredMenuWidgetBase
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

protected:

	// アイテム追加。
	UFUNCTION(BlueprintNativeEvent, Category = "WarpAreaList")
	void AddItem(int32 Id, int32 AreaId, const FString &Name);
	void AddItem_Implementation(int32 Id, int32 AreaId, const FString &Name) {}

	// エリア移動パケット送信.
	UFUNCTION(BlueprintCallable, Category = "WarpAreaList")
	void SendAreaMoveRequest(int32 MoveId, int32 AreaId);

private:

	// アセットのパス
	static const TCHAR *AssetPath;

	// ID
	uint32 Id;
	
};

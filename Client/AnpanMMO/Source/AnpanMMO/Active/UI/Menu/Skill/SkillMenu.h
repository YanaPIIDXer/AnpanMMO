// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "SkillMenu.generated.h"

/**
 * スキルツリーノード
 */
USTRUCT(BlueprintType)
struct FSkillTreeNode
{

	GENERATED_USTRUCT_BODY()

public:

	// ノードＩＤ
	uint32 NodeId;

	// スキルＩＤ
	UPROPERTY(BlueprintReadOnly)
	int32 SkillId;

	// 必要なレベル
	UPROPERTY(BlueprintReadOnly)
	int32 NeedLevel;

	// コスト
	UPROPERTY(BlueprintReadOnly)
	int32 Cost;

	// 開いているか？
	UPROPERTY(BlueprintReadOnly)
	bool bIsOpened;

	// 親ノードが開いているか？
	UPROPERTY(BlueprintReadOnly)
	bool bIsParentOpened;

	// 座標.
	UPROPERTY(BlueprintReadOnly)
	FVector2D Position;

};

/**
 * スキルメニュー
 */
UCLASS()
class ANPANMMO_API USkillMenu : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	USkillMenu(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~USkillMenu() {}

	// パケットを受信した。
	virtual void OnRecvPacket(uint8 ID) override;

protected:

	// メニューの再初期化.
	UFUNCTION(BlueprintNativeEvent, Category = "SkillMenu")
	void RefleshMenu();
	void RefleshMenu_Implementation() {}

};

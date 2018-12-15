// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Skill/SkillTree/SkillTree.h"
#include "SkillTreeWidget.generated.h"

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

	// 開いているか？
	UPROPERTY(BlueprintReadOnly)
	bool bIsOpened;

	// 座標.
	UPROPERTY(BlueprintReadOnly)
	FVector2D Position;
	
};

/**
 * スキルツリー画面.
 */
UCLASS()
class ANPANMMO_API USkillTreeWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	USkillTreeWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~USkillTreeWidget() {}

	// 初期化.
	UFUNCTION(BlueprintCallable, Category = "SkillTree")
	void Init();

protected:

	// 初期化イベント
	UFUNCTION(BlueprintNativeEvent, Category = "SkillTree")
	void InitEvent(const TArray<FSkillTreeNode> &NodeList);
	void InitEvent_Implementation(const TArray<FSkillTreeNode> &NodeList) {}

private:

	// スキルツリーノード生成.
	void GenerateSkillTreeNodeList(SkillTree::Node *pNode, int32 Depth, int32 ChildNo, int32 ChildCount, TArray<FSkillTreeNode> &OutNodeList);

};

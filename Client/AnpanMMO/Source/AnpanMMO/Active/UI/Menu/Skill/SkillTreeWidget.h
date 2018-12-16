// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillMenu.h"
#include "Skill/SkillTree/SkillTree.h"
#include "SkillTreeWidget.generated.h"

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
	
	// 開放リクエスト送信.
	UFUNCTION(BlueprintCallable, Category = "SkillTree")
	void SendOpenRequest(const FSkillTreeNode &Item);

private:

	// スキルツリーノードリスト生成.
	void GenerateSkillTreeNodeList(SkillTree::Node *pNode, SkillTree::Node *pParentNode, TArray<FSkillTreeNode> &OutNodeList);

};

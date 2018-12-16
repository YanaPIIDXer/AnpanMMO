// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkillMenu.h"
#include "Skill/SkillTree/SkillTree.h"
#include "Blueprint/UserWidget.h"
#include "SkillListWidget.generated.h"

/**
 * スキルリスト画面.
 */
UCLASS()
class ANPANMMO_API USkillListWidget : public UUserWidget
{

	GENERATED_BODY()

public:

	// コンストラクタ
	USkillListWidget(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~USkillListWidget() {}

	// 初期化.
	UFUNCTION(BlueprintCallable, Category = "SkillList")
	void Init();

protected:

	// 初期化イベント
	UFUNCTION(BlueprintNativeEvent, Category = "SkillList")
	void InitEvent(const TArray<FSkillTreeNode> &Nodes, int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4);
	void InitEvent_Implementation(const TArray<FSkillTreeNode> &Nodes, int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4) {}

	// スキルリスト保存リクエストを送信.
	UFUNCTION(BlueprintCallable, Category = "SkillList")
	void SendSaveSkillListRequest(int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4);
	
private:

	// 開かれているノードを列挙.
	void CollectOpenedNode(const SkillTree::Node *pNode, TArray<FSkillTreeNode> &OutNodes);

};

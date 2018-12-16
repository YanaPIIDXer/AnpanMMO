// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SkillMenu.h"
#include "Skill/SkillTree/SkillTree.h"
#include "Blueprint/UserWidget.h"
#include "SkillListWidget.generated.h"

/**
 * �X�L�����X�g���.
 */
UCLASS()
class ANPANMMO_API USkillListWidget : public UUserWidget
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	USkillListWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~USkillListWidget() {}

	// ������.
	UFUNCTION(BlueprintCallable, Category = "SkillList")
	void Init();

protected:

	// �������C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "SkillList")
	void InitEvent(const TArray<FSkillTreeNode> &Nodes, int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4);
	void InitEvent_Implementation(const TArray<FSkillTreeNode> &Nodes, int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4) {}

	// �X�L�����X�g�ۑ����N�G�X�g�𑗐M.
	UFUNCTION(BlueprintCallable, Category = "SkillList")
	void SendSaveSkillListRequest(int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4);
	
private:

	// �J����Ă���m�[�h���.
	void CollectOpenedNode(const SkillTree::Node *pNode, TArray<FSkillTreeNode> &OutNodes);

};

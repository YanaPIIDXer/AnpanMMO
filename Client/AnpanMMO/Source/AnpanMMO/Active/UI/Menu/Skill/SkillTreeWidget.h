// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillMenu.h"
#include "Skill/SkillTree/SkillTree.h"
#include "SkillTreeWidget.generated.h"

/**
 * �X�L���c���[���.
 */
UCLASS()
class ANPANMMO_API USkillTreeWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// �R���X�g���N�^
	USkillTreeWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~USkillTreeWidget() {}

	// ������.
	UFUNCTION(BlueprintCallable, Category = "SkillTree")
	void Init();

protected:

	// �������C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "SkillTree")
	void InitEvent(const TArray<FSkillTreeNode> &NodeList);
	void InitEvent_Implementation(const TArray<FSkillTreeNode> &NodeList) {}
	
	// �J�����N�G�X�g���M.
	UFUNCTION(BlueprintCallable, Category = "SkillTree")
	void SendOpenRequest(const FSkillTreeNode &Item);

private:

	// �X�L���c���[�m�[�h���X�g����.
	void GenerateSkillTreeNodeList(SkillTree::Node *pNode, SkillTree::Node *pParentNode, TArray<FSkillTreeNode> &OutNodeList);

};

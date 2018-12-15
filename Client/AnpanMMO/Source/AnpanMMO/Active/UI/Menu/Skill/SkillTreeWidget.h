// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Skill/SkillTree/SkillTree.h"
#include "SkillTreeWidget.generated.h"

/**
 * �X�L���c���[�m�[�h
 */
USTRUCT(BlueprintType)
struct FSkillTreeNode
{

	GENERATED_USTRUCT_BODY()

public:

	// �m�[�h�h�c
	uint32 NodeId;

	// �X�L���h�c
	UPROPERTY(BlueprintReadOnly)
	int32 SkillId;

	// �K�v�ȃ��x��
	UPROPERTY(BlueprintReadOnly)
	int32 NeedLevel;

	// �R�X�g
	UPROPERTY(BlueprintReadOnly)
	int32 Cost;

	// �J���Ă��邩�H
	UPROPERTY(BlueprintReadOnly)
	bool bIsOpened;

	// �e�m�[�h���J���Ă��邩�H
	UPROPERTY(BlueprintReadOnly)
	bool bIsParentOpened;

	// ���W.
	UPROPERTY(BlueprintReadOnly)
	FVector2D Position;
	
};

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

private:

	// �X�L���c���[�m�[�h����.
	void GenerateSkillTreeNodeList(SkillTree::Node *pNode, SkillTree::Node *pParentNode, TArray<FSkillTreeNode> &OutNodeList);

};

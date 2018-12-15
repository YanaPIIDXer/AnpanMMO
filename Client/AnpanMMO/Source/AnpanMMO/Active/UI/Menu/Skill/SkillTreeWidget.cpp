// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillTreeWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Player/GameCharacter.h"

// �R���X�g���N�^
USkillTreeWidget::USkillTreeWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// ������.
void USkillTreeWidget::Init()
{
	AGameCharacter *pChara = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	check(pChara != nullptr);

	SkillTree::Node *pRootNode = pChara->GetStatus().GetSkillTree().GetNode();
	TArray<FSkillTreeNode> NodeList;

	if (pRootNode != nullptr)
	{
		GenerateSkillTreeNodeList(pRootNode, NodeList);
	}
	
	InitEvent(NodeList);
}


// �X�L���c���[�m�[�h����.
void USkillTreeWidget::GenerateSkillTreeNodeList(SkillTree::Node *pNode, TArray<FSkillTreeNode> &OutNodeList)
{
	FSkillTreeNode Data;
	Data.NodeId = pNode->NodeId;
	Data.SkillId = pNode->SkillId;
	Data.NeedLevel = pNode->NeedLevel;
	Data.bIsOpened = pNode->bIsOpened;
	Data.Position = pNode->NodePosition;
	OutNodeList.Add(Data);

	for(auto *pChild : pNode->Children)
	{
		GenerateSkillTreeNodeList(pChild, OutNodeList);
	}
}

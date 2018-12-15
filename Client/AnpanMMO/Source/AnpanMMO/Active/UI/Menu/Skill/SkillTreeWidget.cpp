// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillTreeWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Player/GameCharacter.h"

// コンストラクタ
USkillTreeWidget::USkillTreeWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// 初期化.
void USkillTreeWidget::Init()
{
	AGameCharacter *pChara = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	check(pChara != nullptr);

	SkillTree::Node *pRootNode = pChara->GetStatus().GetSkillTree().GetNode();
	TArray<FSkillTreeNode> NodeList;

	if (pRootNode != nullptr)
	{
		GenerateSkillTreeNodeList(pRootNode, 0, 0, 1, NodeList);
	}
	
	InitEvent(NodeList);
}


// スキルツリーノード生成.
void USkillTreeWidget::GenerateSkillTreeNodeList(SkillTree::Node *pNode, int32 Depth, int32 ChildNo, int32 ChildCount, TArray<FSkillTreeNode> &OutNodeList)
{
	FSkillTreeNode Data;
	Data.NodeId = pNode->NodeId;
	Data.SkillId = pNode->SkillId;
	Data.NeedLevel = pNode->NeedLevel;
	Data.bIsOpened = pNode->bIsOpened;
	Data.Position.X = (ChildCount / (ChildNo + 1)) * 200.0f + 300.0f;
	Data.Position.Y = Depth * 250.0f;
	OutNodeList.Add(Data);

	for(int32 i = 0; i < pNode->Children.Num(); i++)
	{
		SkillTree::Node *pChild = pNode->Children[i];
		GenerateSkillTreeNodeList(pChild, Depth + 1, i, pNode->Children.Num(), OutNodeList);
	}
}

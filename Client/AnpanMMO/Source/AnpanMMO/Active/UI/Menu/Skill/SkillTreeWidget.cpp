// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillTreeWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Player/GameCharacter.h"
#include "MMOGameInstance.h"
#include "Packet/PacketSkillTreeOpenRequest.h"

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

	SkillTree::Node RootNode = pChara->GetStatus().GetSkillTree().GetRootNode();
	TArray<FSkillTreeNode> NodeList;

	if (RootNode.NodeId != 0)
	{
		GenerateSkillTreeNodeList(&RootNode, nullptr, NodeList);
	}
	
	InitEvent(NodeList);
}


// 開放リクエスト送信.
void USkillTreeWidget::SendOpenRequest(const FSkillTreeNode &Item)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketSkillTreeOpenRequest Packet(Item.NodeId);
	pInst->SendPacket(&Packet);
}


// スキルツリーノードリスト生成.
void USkillTreeWidget::GenerateSkillTreeNodeList(const SkillTree::Node *pNode, const SkillTree::Node *pParentNode, TArray<FSkillTreeNode> &OutNodeList)
{
	FSkillTreeNode Data;
	Data.NodeId = pNode->NodeId;
	Data.SkillId = pNode->SkillId;
	Data.NeedLevel = pNode->NeedLevel;
	Data.Cost = pNode->Cost;
	Data.bIsOpened = pNode->bIsOpened;
	Data.bIsParentOpened = (pParentNode != nullptr ? pParentNode->bIsOpened : true);
	Data.Position = pNode->NodePosition;
	OutNodeList.Add(Data);

	for (const auto *pChild : pNode->Children)
	{
		GenerateSkillTreeNodeList(pChild, pNode, OutNodeList);
	}
}

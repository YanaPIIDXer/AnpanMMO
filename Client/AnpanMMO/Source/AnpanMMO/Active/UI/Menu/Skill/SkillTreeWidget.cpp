// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillTreeWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Player/GameCharacter.h"
#include "MMOGameInstance.h"
#include "Packet/PacketSkillTreeOpenRequest.h"

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
		GenerateSkillTreeNodeList(pRootNode, nullptr, NodeList);
	}
	
	InitEvent(NodeList);
}


// �J�����N�G�X�g���M.
void USkillTreeWidget::SendOpenRequest(const FSkillTreeNode &Item)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketSkillTreeOpenRequest Packet(Item.NodeId);
	pInst->SendPacket(&Packet);
}


// �X�L���c���[�m�[�h���X�g����.
void USkillTreeWidget::GenerateSkillTreeNodeList(SkillTree::Node *pNode, SkillTree::Node *pParentNode, TArray<FSkillTreeNode> &OutNodeList)
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

	for(auto *pChild : pNode->Children)
	{
		GenerateSkillTreeNodeList(pChild, pNode, OutNodeList);
	}
}

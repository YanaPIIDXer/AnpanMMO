// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "SkillListWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Player/GameCharacter.h"
#include "MMOGameInstance.h"
#include "Packet/PacketSaveSkillListRequest.h"

// �R���X�g���N�^
USkillListWidget::USkillListWidget(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// ������.
void USkillListWidget::Init()
{
	AGameCharacter *pChara = Cast<AGameCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	check(pChara != nullptr);

	SkillTree::Node *pRootNode = pChara->GetStatus().GetSkillTree().GetNode();
	TArray<FSkillTreeNode> Nodes;
	if (pRootNode != nullptr)
	{
		CollectOpenedNode(pRootNode, Nodes);
	}

	const TArray<uint32> &SkillList = pChara->GetStatus().GetSkillList();

	InitEvent(Nodes, SkillList[1], SkillList[2], SkillList[3], SkillList[4]);
}


// �X�L�����X�g�ۑ����N�G�X�g�𑗐M.
void USkillListWidget::SendSaveSkillListRequest(int32 Skill1, int32 Skill2, int32 Skill3, int32 Skill4)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	PacketSaveSkillListRequest Packet(Skill1, Skill2, Skill3, Skill4);
	pInst->SendPacket(&Packet);
}


// �J����Ă���m�[�h���.
void USkillListWidget::CollectOpenedNode(SkillTree::Node *pNode, TArray<FSkillTreeNode> &OutNodes)
{
	if (pNode->bIsOpened)
	{
		FSkillTreeNode Item;
		Item.NodeId = pNode->NodeId;
		Item.SkillId = pNode->SkillId;
		OutNodes.Add(Item);
	}

	for (auto *pChild : pNode->Children)
	{
		CollectOpenedNode(pChild, OutNodes);
	}
}

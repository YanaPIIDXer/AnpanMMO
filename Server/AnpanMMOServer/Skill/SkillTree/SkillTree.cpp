#include "stdafx.h"
#include "SkillTree.h"
#include "Character/Player/PlayerCharacter.h"
#include "Master/MasterData.h"
#include "Packet/SkillTreeNode.h"

// コンストラクタ
SkillTree::SkillTree(PlayerCharacter *pInCharacter)
	: pCharacter(pInCharacter)
{
	std::vector<SkillTreeItem> Items = MasterData::GetInstance().GetSkillTreeMaster().GetAll();
	for (u32 i = 0; i < Items.size(); i++)
	{
		if (Items[i].Job != pCharacter->GetJob()) { continue; }
		Node Nd;
		Nd.Cost = Items[i].Cost;
		Nd.bIsOpened = false;
		Nodes[Items[i].ID] = Nd;
	}
}

// 開く
bool SkillTree::Open(u32 NodeId)
{
	if (Nodes.find(NodeId) == Nodes.end()) { return false; }
	Nodes[NodeId].bIsOpened = true;
	return true;
}

// 既に開かれているか？
bool SkillTree::IsOpened(u32 NodeId, bool &bOutOpened)
{
	if (Nodes.find(NodeId) == Nodes.end()) { return false; }
	bOutOpened = Nodes[NodeId].bIsOpened;
	return true;
}

// クライアントに送り付けるノードデータリストを生成,
void SkillTree::GenerateNodeDataList(FlexArray<SkillTreeNode> &OutDataList) const
{
	for (NodeMap::const_iterator It = Nodes.begin(); It != Nodes.end(); ++It)
	{
		u8 State = SkillTreeNode::Closed;
		if (It->second.bIsOpened)
		{
			State = SkillTreeNode::Open;
		}
		SkillTreeNode Data(It->first, State);
		OutDataList.PushBack(Data);
	}
}

#include "stdafx.h"
#include "SkillTree.h"
#include "Master/MasterData.h"
#include "Packet/SkillTreeNode.h"

// コンストラクタ
SkillTree::SkillTree(u8 Job)
{
	std::vector<SkillTreeItem> Items = MasterData::GetInstance().GetSkillTreeMaster().GetAll();
	for (u32 i = 0; i < Items.size(); i++)
	{
		if (Items[i].Job != Job) { continue; }
		Node Nd;
		Nd.Cost = Items[i].Cost;
		Nd.SkillId = Items[i].SkillId;
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
bool SkillTree::IsOpened(u32 NodeId, bool &bOutOpened) const
{
	NodeMap::const_iterator It = Nodes.find(NodeId);
	if (It == Nodes.end()) { return false; }
	bOutOpened = It->second.bIsOpened;
	return true;
}

// スキルＩＤを取得.
bool SkillTree::GetSkillId(u32 NodeId, u32 &OutSkillId) const
{
	NodeMap::const_iterator It = Nodes.find(NodeId);
	if (It == Nodes.end()) { return false; }
	OutSkillId = It->second.SkillId;
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

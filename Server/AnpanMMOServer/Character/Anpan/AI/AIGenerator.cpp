/**
 * @file AIGenerator.h
 * @brief ＡＩ機構構築クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "AIGenerator.h"
#include "Master/MasterData.h"

AIGenerator AIGenerator::Instance;

// コンストラクタ	
AIGenerator::AIGenerator()
{
}

// 初期化,
void AIGenerator::Initialize()
{
	for (int i = 0; ; i++)
	{
		std::vector<AnpanAIItem> Items = MasterData::GetInstance().GetAnpanAIMaster().GetAllSheetItem(i);
		if (Items.size() == 0) { break; }

		std::vector<AIActionSharedPtr> ActionList;

		for (std::vector<AnpanAIItem>::iterator It = Items.begin(); It != Items.end(); ++It)
		{
			AIActionSharedPtr pAction = AIActionSharedPtr(new AIAction());
			pAction->Action = It->Action;
			pAction->Value = It->Value;
			ActionList.push_back(pAction);
		}

		Actions[i] = ActionList;
	}

	// 行動リンクの構築.
	for (ActionMap::iterator It = Actions.begin(); It != Actions.end(); ++It)
	{
		std::vector<AIActionSharedPtr> &ActionList = It->second;
		for (u32 i = 0; i < ActionList.size(); i++)
		{
			if (ActionList[i].get()->Action != AnpanAIItem::CHANGE_STAGE)
			{
				if (i < ActionList.size() - 1)
				{
					ActionList[i].get()->pNextAction = ActionList[i + 1];
				}
				else
				{
					ActionList[i].get()->pNextAction = ActionList[0];
				}
			}
			else
			{
				ActionList[i].get()->pNextAction = Actions[ActionList[i].get()->Value][0];
			}
		}
	}
}

// 取得.
const AIActionPtr AIGenerator::Get(u32 Id) const
{
	ActionMap::const_iterator It = Actions.find(Id);
	if (It == Actions.end()) { return AIActionPtr(); }
	return It->second[0];
}

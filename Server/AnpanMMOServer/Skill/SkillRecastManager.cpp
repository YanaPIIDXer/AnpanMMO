#include "stdafx.h"
#include "SkillRecastManager.h"
#include "Master/MasterData.h"

// コンストラクタ
SkillRecastManager::SkillRecastManager(CharacterBase *pInOwner)
	: pOwner(pInOwner)
{
}

// 毎フレームの処理.
void SkillRecastManager::Poll(s32 DeltaTime)
{
	for (RecastMap::iterator It = RecastList.begin(); It != RecastList.end();)
	{
		It->second -= DeltaTime;
		if (It->second <= 0)
		{
			if (RecastFinishedFunc)
			{
				RecastFinishedFunc(It->first);
			}
			It = RecastList.erase(It);
		}
		else
		{
			++It;
		}
	}
}

// 追加.
void SkillRecastManager::Add(u32 SkillId)
{
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(SkillId);
	RecastList[SkillId] = pItem->RecastTime * 1000;
}

// リキャスト中か？
bool SkillRecastManager::IsRecast(u32 SkillId) const
{
	return (RecastList.find(SkillId) != RecastList.end());
}

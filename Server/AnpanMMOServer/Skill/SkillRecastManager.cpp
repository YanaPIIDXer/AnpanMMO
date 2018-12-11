#include "stdafx.h"
#include "SkillRecastManager.h"
#include "Master/MasterData.h"

// �R���X�g���N�^
SkillRecastManager::SkillRecastManager(CharacterBase *pInOwner)
	: pOwner(pInOwner)
{
}

// ���t���[���̏���.
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

// �ǉ�.
void SkillRecastManager::Add(u32 SkillId)
{
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().GetItem(SkillId);
	RecastList[SkillId] = pItem->RecastTime * 1000;
}

// ���L���X�g�����H
bool SkillRecastManager::IsRecast(u32 SkillId) const
{
	return (RecastList.find(SkillId) != RecastList.end());
}

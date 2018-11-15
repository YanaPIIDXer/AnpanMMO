#include "stdafx.h"
#include "AreaManager.h"
#include "TickManager.h"
#include "Master/MasterData.h"
#include "Area.h"

AreaManager AreaManager::Instance;

// �R���X�g���N�^
AreaManager::AreaManager()
{
}

// ������.
void AreaManager::Initialize()
{
	TickManager::GetInstance().Add(boost::bind(&AreaManager::Poll, this, _1));

	std::vector<AreaItem> Items = MasterData::GetInstance().GetAreaMaster().GetAll();
	for (int i = 0; i < Items.size(); i++)
	{
		const AreaItem *pItem = MasterData::GetInstance().GetAreaMaster().GetItem(Items[i].ID);
		Area *pArea = new Area(pItem);
		AreaSharedPtr pSharedArea = AreaSharedPtr(pArea);
		Areas[pItem->ID] = pSharedArea;
	}
}

// ���t���[���̏���.
void AreaManager::Poll(int DeltaTime)
{
	for (AreaMap::iterator It = Areas.begin(); It != Areas.end(); ++It)
	{
		It->second->Poll(DeltaTime);
	}
}

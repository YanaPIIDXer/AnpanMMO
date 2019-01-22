/**
 * @file ShopManager.cpp
 * @brief ショップ管理クラス
 * @author YanaP
 */
#include "stdafx.h"
#include "ShopManager.h"
#include "Master/MasterData.h"

ShopManager ShopManager::Instance;

// コンストラクタ
ShopManager::ShopManager()
{
}

// デストラクタ
ShopManager::~ShopManager()
{
	for (ShopMap::iterator It = ShopData.begin(); It != ShopData.end();)
	{
		delete It->second;
		It = ShopData.erase(It);
	}
}

// 初期化
void ShopManager::Initialize()
{
	std::vector<ShopItem> Items = MasterData::GetInstance().GetShopMaster().GetAll();
	for (u32 i = 0; i < Items.size(); i++)
	{
		const ShopItem &Item = Items[i];
		if (ShopData.find(Item.ID) == ShopData.end())
		{
			ShopData[Item.ID] = new ItemList();
		}
		ShopData[Item.ID]->push_back(Item.ItemId);
	}
}

// 売っているか？
bool ShopManager::IsSelling(u32 ShopId, u32 ItemId) const
{
	if (!IsValidShop(ShopId)) { return false; }
	const ItemList *pList = ShopData.find(ShopId)->second;
	for (ItemList::const_iterator It = pList->begin(); It != pList->end(); ++It)
	{
		if (*It == ItemId) { return true; }
	}
	return false;
}

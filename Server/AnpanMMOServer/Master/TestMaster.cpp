#include "stdafx.h"
#include "TestMaster.h"
#include "MySQL/MySqlConnection.h"

// 読み込み。
bool TestMaster::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from Test;");

	TestItem BindItem;
	char NameBind[128];
	Query.BindResultInt(&BindItem.ID);
	Query.BindResultString(NameBind);
	Query.BindResultInt(&BindItem.Hp);
	Query.BindResultInt(&BindItem.Mp);
	Query.BindResultInt(&BindItem.Exp);

	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		TestItem Item;
		Item.ID = BindItem.ID;
		Item.Name = NameBind;
		Item.Hp = BindItem.Hp;
		Item.Mp = BindItem.Mp;
		Item.Exp = BindItem.Exp;

		Items[Item.ID] = Item;
	}

	return true;
}

// アイテム取得.
const TestItem *TestMaster::GetItem(u32 Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

// 全取得.
std::vector<TestItem> TestMaster::GetAll() const
{
	std::vector<TestItem> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

// ソート用オペレータオーバーロード
bool operator <(const TestItem &A, const TestItem &B)
{
	return (A.ID < B.ID);
}

bool operator >(const TestItem &A, const TestItem &B)
{
	return (A.ID > B.ID);
}

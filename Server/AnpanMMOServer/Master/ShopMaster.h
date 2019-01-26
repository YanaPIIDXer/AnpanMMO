#ifndef __SHOPMASTER_H__
#define __SHOPMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct ShopItem
{

public:



	s32 AutoKey;
	u32 ID;
	u32 ItemId;


};

bool operator <(const ShopItem &A, const ShopItem &B);
bool operator >(const ShopItem &A, const ShopItem &B);

class ShopMaster
{

private:

	typedef std::map<u32, ShopItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	std::vector<const ShopItem *> CollectItems(u32 Key, s32 SheetIndex = 0) const;

	std::vector<ShopItem> GetAllSheetItem(s32 SheetIndex) const;

	std::vector<ShopItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __SHOPMASTER_H__

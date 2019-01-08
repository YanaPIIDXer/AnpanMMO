#ifndef __ITEMDROPMASTER_H__
#define __ITEMDROPMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct ItemDropItem
{

public:

	enum
	{
		NONE = 0,
		ITEM = 1,
		GOLD = 2,
	};


	u32 ID;
	u8 Type1;
	u32 Id1;
	u32 Count1;
	u8 Type2;
	u32 Id2;
	u32 Count2;
	u8 Type3;
	u32 Id3;
	u32 Count3;


};

bool operator <(const ItemDropItem &A, const ItemDropItem &B);
bool operator >(const ItemDropItem &A, const ItemDropItem &B);

class ItemDropMaster
{

private:

	typedef std::map<u32, ItemDropItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const ItemDropItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<ItemDropItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __ITEMDROPMASTER_H__

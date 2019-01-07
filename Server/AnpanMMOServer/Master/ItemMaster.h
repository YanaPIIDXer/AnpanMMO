#ifndef __ITEMMASTER_H__
#define __ITEMMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct ItemItem
{

public:

	enum
	{
		CONSUME = 0,
		DELIVERY = 1,
	};


	u32 ID;
	std::string Name;
	u8 Type;
	u32 BuyGold;
	u32 SellGold;
	u32 SkillId;


};

bool operator <(const ItemItem &A, const ItemItem &B);
bool operator >(const ItemItem &A, const ItemItem &B);

class ItemMaster
{

private:

	typedef std::map<u32, ItemItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const ItemItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<ItemItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __ITEMMASTER_H__

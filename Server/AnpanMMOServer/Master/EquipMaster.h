#ifndef __EQUIPMASTER_H__
#define __EQUIPMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct EquipItem
{

public:



	u32 ID;
	std::string Name;
	u32 Str;
	u32 Def;
	u32 Int;
	u32 Mnd;
	u32 Vit;
	u32 NormalAttackId;
	u32 BuyGold;
	u32 SellGold;


};

bool operator <(const EquipItem &A, const EquipItem &B);
bool operator >(const EquipItem &A, const EquipItem &B);

class EquipMaster
{

private:

	typedef std::map<u32, EquipItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const EquipItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<EquipItem> GetAllSheetItem(s32 SheetIndex) const;

	std::vector<EquipItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __EQUIPMASTER_H__

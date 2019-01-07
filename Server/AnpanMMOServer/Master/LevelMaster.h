#ifndef __LEVELMASTER_H__
#define __LEVELMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct LevelItem
{

public:



	u32 Level;
	u32 MaxHP;
	u32 STR;
	u32 DEF;
	u32 INT;
	u32 MND;
	u32 VIT;
	u32 NextExp;


};

bool operator <(const LevelItem &A, const LevelItem &B);
bool operator >(const LevelItem &A, const LevelItem &B);

class LevelMaster
{

private:

	typedef std::map<u32, LevelItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const LevelItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<LevelItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __LEVELMASTER_H__

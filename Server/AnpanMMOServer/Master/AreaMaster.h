#ifndef __AREAMASTER_H__
#define __AREAMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct AreaItem
{

public:

	u32 ID;
	std::string Name;
	u32 AnpanMax;
	s32 AnpanMinHp;
	s32 AnpanMaxHp;
	s32 AnpanMinAtk;
	s32 AnpanMaxAtk;
	s32 AnpanMinDef;
	s32 AnpanMaxDef;
	s32 AnpanMinExp;
	s32 AnpanMaxExp;


};

bool operator <(const AreaItem &A, const AreaItem &B);
bool operator >(const AreaItem &A, const AreaItem &B);

class AreaMaster
{

private:

	typedef std::map<u32, AreaItem> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	const AreaItem *GetItem(u32 Key) const;

	std::vector<AreaItem> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __AREAMASTER_H__

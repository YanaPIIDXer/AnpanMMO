#ifndef __ANPANPOPAREAMASTER_H__
#define __ANPANPOPAREAMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct AnpanPopAreaItem
{

public:

	s32 AutoKey;
	u32 AreaId;
	float X;
	float Y;
	float Range;
	s32 AnpanMinHp;
	s32 AnpanMaxHp;
	s32 AnpanMinAtk;
	s32 AnpanMaxAtk;
	s32 AnpanMinDef;
	s32 AnpanMaxDef;
	s32 AnpanMinExp;
	s32 AnpanMaxExp;


};

bool operator <(const AnpanPopAreaItem &A, const AnpanPopAreaItem &B);
bool operator >(const AnpanPopAreaItem &A, const AnpanPopAreaItem &B);

class AnpanPopAreaMaster
{

private:

	typedef std::map<u32, AnpanPopAreaItem> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	std::vector<const AnpanPopAreaItem *> CollectItems(u32 Key) const;

	std::vector<AnpanPopAreaItem> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __ANPANPOPAREAMASTER_H__

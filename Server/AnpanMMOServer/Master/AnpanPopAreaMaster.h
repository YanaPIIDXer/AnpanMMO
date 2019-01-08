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
	float Z;
	float Range;
	s32 PopInterval;
	u32 MaxCount;
	u32 PopId;


};

bool operator <(const AnpanPopAreaItem &A, const AnpanPopAreaItem &B);
bool operator >(const AnpanPopAreaItem &A, const AnpanPopAreaItem &B);

class AnpanPopAreaMaster
{

private:

	typedef std::map<u32, AnpanPopAreaItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	std::vector<const AnpanPopAreaItem *> CollectItems(u32 Key, s32 SheetIndex = 0) const;

	std::vector<AnpanPopAreaItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __ANPANPOPAREAMASTER_H__

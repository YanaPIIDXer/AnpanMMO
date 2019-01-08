#ifndef __ANPANPOPDATAMASTER_H__
#define __ANPANPOPDATAMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct AnpanPopDataItem
{

public:



	s32 AutoKey;
	u32 Id;
	u32 AnpanId;


};

bool operator <(const AnpanPopDataItem &A, const AnpanPopDataItem &B);
bool operator >(const AnpanPopDataItem &A, const AnpanPopDataItem &B);

class AnpanPopDataMaster
{

private:

	typedef std::map<u32, AnpanPopDataItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	std::vector<const AnpanPopDataItem *> CollectItems(u32 Key, s32 SheetIndex = 0) const;

	std::vector<AnpanPopDataItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __ANPANPOPDATAMASTER_H__

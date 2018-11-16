#ifndef __WARPDATAMASTER_H__
#define __WARPDATAMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct WarpDataItem
{

public:

	s32 AutoKey;
	u32 ID;
	u32 AreaId;
	float X;
	float Y;


};

bool operator <(const WarpDataItem &A, const WarpDataItem &B);
bool operator >(const WarpDataItem &A, const WarpDataItem &B);

class WarpDataMaster
{

private:

	typedef std::map<u32, WarpDataItem> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	std::vector<const WarpDataItem *> CollectItems(u32 Key) const;

	std::vector<WarpDataItem> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __WARPDATAMASTER_H__

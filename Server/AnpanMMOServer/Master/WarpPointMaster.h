#ifndef __WARPPOINTMASTER_H__
#define __WARPPOINTMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct WarpPointItem
{

public:

	u32 Id;
	u32 AreaId;
	float X;
	float Y;
	u32 WarpDataId;


};

bool operator <(const WarpPointItem &A, const WarpPointItem &B);
bool operator >(const WarpPointItem &A, const WarpPointItem &B);

class WarpPointMaster
{

private:

	typedef std::map<u32, WarpPointItem> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	const WarpPointItem *GetItem(u32 Key) const;

	std::vector<WarpPointItem> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __WARPPOINTMASTER_H__

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
	float Z;
	u32 WarpDataId;


};

bool operator <(const WarpPointItem &A, const WarpPointItem &B);
bool operator >(const WarpPointItem &A, const WarpPointItem &B);

class WarpPointMaster
{

private:

	typedef std::map<u32, WarpPointItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const WarpPointItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<WarpPointItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __WARPPOINTMASTER_H__

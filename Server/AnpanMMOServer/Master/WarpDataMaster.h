#ifndef __WARPDATAMASTER_H__
#define __WARPDATAMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct WarpDataItem
{

public:



	u32 ID;
	u32 WarpDataId;
	u32 AreaId;
	float X;
	float Y;
	float Z;


};

bool operator <(const WarpDataItem &A, const WarpDataItem &B);
bool operator >(const WarpDataItem &A, const WarpDataItem &B);

class WarpDataMaster
{

private:

	typedef std::map<u32, WarpDataItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const WarpDataItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<WarpDataItem> GetAllSheetItem(s32 SheetIndex) const;

	std::vector<WarpDataItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __WARPDATAMASTER_H__

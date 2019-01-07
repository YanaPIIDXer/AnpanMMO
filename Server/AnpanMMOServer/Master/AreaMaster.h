#ifndef __AREAMASTER_H__
#define __AREAMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct AreaItem
{

public:

	enum
	{
		NORMAL_AREA = 0,
		INSTANCE_AREA = 1,
	};


	u32 ID;
	std::string Name;
	std::string LevelName;
	u8 Type;
	u32 InstanceInfoId;


};

bool operator <(const AreaItem &A, const AreaItem &B);
bool operator >(const AreaItem &A, const AreaItem &B);

class AreaMaster
{

private:

	typedef std::map<u32, AreaItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const AreaItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<AreaItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __AREAMASTER_H__

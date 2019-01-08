#ifndef __INSTANCEINFOMASTER_H__
#define __INSTANCEINFOMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct InstanceInfoItem
{

public:



	u32 Id;
	u32 BossId;
	float BossX;
	float BossY;
	float BossZ;
	u32 ExitWarpPointId;


};

bool operator <(const InstanceInfoItem &A, const InstanceInfoItem &B);
bool operator >(const InstanceInfoItem &A, const InstanceInfoItem &B);

class InstanceInfoMaster
{

private:

	typedef std::map<u32, InstanceInfoItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const InstanceInfoItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<InstanceInfoItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __INSTANCEINFOMASTER_H__

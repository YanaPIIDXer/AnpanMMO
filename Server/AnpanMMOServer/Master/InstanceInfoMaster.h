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
	u32 ExitWarpDataId;


};

bool operator <(const InstanceInfoItem &A, const InstanceInfoItem &B);
bool operator >(const InstanceInfoItem &A, const InstanceInfoItem &B);

class InstanceInfoMaster
{

private:

	typedef std::map<u32, InstanceInfoItem> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	const InstanceInfoItem *GetItem(u32 Key) const;

	std::vector<InstanceInfoItem> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __INSTANCEINFOMASTER_H__
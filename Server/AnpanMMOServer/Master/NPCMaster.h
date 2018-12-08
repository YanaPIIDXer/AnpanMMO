#ifndef __NPCMASTER_H__
#define __NPCMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct NPCItem
{

public:



	u32 ID;
	std::string Name;
	u32 AreaId;
	float X;
	float Y;
	float Z;
	float Rotation;
	std::string ScriptName;
	u32 AppearConditionId;
	u32 EraseConditionId;
	u32 ResourceId;


};

bool operator <(const NPCItem &A, const NPCItem &B);
bool operator >(const NPCItem &A, const NPCItem &B);

class NPCMaster
{

private:

	typedef std::map<u32, NPCItem> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	const NPCItem *GetItem(u32 Key) const;

	std::vector<NPCItem> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __NPCMASTER_H__

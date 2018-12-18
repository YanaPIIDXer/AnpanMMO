#ifndef __QUESTSTAGEMASTER_H__
#define __QUESTSTAGEMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct QuestStageItem
{

public:

	enum
	{
		NPC = 0,
		KILL_ANPAN = 1,
	};


	u32 Id;
	u8 Condition;
	u32 AreaId;
	u32 Count;
	u32 NextStageId;


};

bool operator <(const QuestStageItem &A, const QuestStageItem &B);
bool operator >(const QuestStageItem &A, const QuestStageItem &B);

class QuestStageMaster
{

private:

	typedef std::map<u32, QuestStageItem> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	const QuestStageItem *GetItem(u32 Key) const;

	std::vector<QuestStageItem> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __QUESTSTAGEMASTER_H__

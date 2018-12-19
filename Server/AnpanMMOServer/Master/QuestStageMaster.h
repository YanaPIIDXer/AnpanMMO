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
		KILL_ANPAN_IN_AREA = 1,
		COLLECT_ITEM = 2,
	};


	u32 Id;
	u8 Condition;
	u32 TargetId;
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
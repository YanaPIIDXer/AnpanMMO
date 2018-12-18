#ifndef __QUESTMASTER_H__
#define __QUESTMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct QuestItem
{

public:



	u32 Id;
	std::string Name;
	u32 StartStageId;
	u32 RewardId;
	u32 NextQuestId;


};

bool operator <(const QuestItem &A, const QuestItem &B);
bool operator >(const QuestItem &A, const QuestItem &B);

class QuestMaster
{

private:

	typedef std::map<u32, QuestItem> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	const QuestItem *GetItem(u32 Key) const;

	std::vector<QuestItem> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __QUESTMASTER_H__

#ifndef __QUESTREWARDMASTER_H__
#define __QUESTREWARDMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct QuestRewardItem
{

public:

	enum
	{
		NONE = 0,
		ITEM = 1,
		GOLD = 2,
	};


	u32 ID;
	u8 Type;
	u32 ItemId;
	u32 Count;


};

bool operator <(const QuestRewardItem &A, const QuestRewardItem &B);
bool operator >(const QuestRewardItem &A, const QuestRewardItem &B);

class QuestRewardMaster
{

private:

	typedef std::map<u32, QuestRewardItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const QuestRewardItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<QuestRewardItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __QUESTREWARDMASTER_H__

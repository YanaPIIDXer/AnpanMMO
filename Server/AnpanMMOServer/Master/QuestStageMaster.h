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
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const QuestStageItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<QuestStageItem> GetAllSheetItem(s32 SheetIndex) const;

	std::vector<QuestStageItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __QUESTSTAGEMASTER_H__

#ifndef __SKILLTREEMASTER_H__
#define __SKILLTREEMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct SkillTreeItem
{

public:

	enum
	{
		FIGHTER = 0,
		SORCERER = 1,
		HEALER = 2,
		LANCER = 3,
	};


	u32 ID;
	u8 Job;
	u32 SkillId;
	u32 NeedLevel;
	u32 Cost;
	float NodeX;
	float NodeY;
	u32 ParentNode;


};

bool operator <(const SkillTreeItem &A, const SkillTreeItem &B);
bool operator >(const SkillTreeItem &A, const SkillTreeItem &B);

class SkillTreeMaster
{

private:

	typedef std::map<u32, SkillTreeItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const SkillTreeItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<SkillTreeItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __SKILLTREEMASTER_H__

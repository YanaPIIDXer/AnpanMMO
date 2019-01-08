#ifndef __SKILLMASTER_H__
#define __SKILLMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct SkillItem
{

public:

	enum
	{
		ATTACK = 0,
		HEAL = 1,
		BUFF = 2,
		DEBUFF = 3,
		ITEM_HEAL = 4,
	};
	enum
	{
		NORMAL = 0,
		RANGE_CIRCLE = 1,
		RANGE_BOX = 2,
	};


	u32 ID;
	std::string Name;
	u8 SkillType;
	u8 RangeType;
	s32 Distance;
	s32 RangeX;
	s32 RangeY;
	s32 CastTime;
	s32 RecastTime;
	u32 BonusStr;
	u32 BonusMnd;
	u32 BonusVit;


};

bool operator <(const SkillItem &A, const SkillItem &B);
bool operator >(const SkillItem &A, const SkillItem &B);

class SkillMaster
{

private:

	typedef std::map<u32, SkillItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const SkillItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<SkillItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __SKILLMASTER_H__

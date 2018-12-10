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


};

bool operator <(const SkillItem &A, const SkillItem &B);
bool operator >(const SkillItem &A, const SkillItem &B);

class SkillMaster
{

private:

	typedef std::map<u32, SkillItem> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	const SkillItem *GetItem(u32 Key) const;

	std::vector<SkillItem> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __SKILLMASTER_H__

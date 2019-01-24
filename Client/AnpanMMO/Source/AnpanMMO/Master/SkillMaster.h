#ifndef __SKILLMASTER_H__
#define __SKILLMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

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
	enum
	{
		PHYSICAL = 0,
		MAGIC = 1,
	};


	u32 ID;
	FString Name;
	u8 SkillType;
	u8 RangeType;
	u8 CalcType;
	s32 Distance;
	s32 RangeX;
	s32 RangeY;
	s32 CastTime;
	s32 RecastTime;
	u32 BonusStr;
	u32 BonusInt;
	u32 BonusMnd;
	u32 BonusVit;
	u32 VolatileHate;
	u32 AccumulateHate;
	u32 BuffId;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		std::string StrName;
		if(!pStream->Serialize(&StrName)) { return false; }
		Name = UTF8_TO_TCHAR(StrName.c_str());
		if(!pStream->Serialize(&SkillType)) { return false; }
		if(!pStream->Serialize(&RangeType)) { return false; }
		if(!pStream->Serialize(&CalcType)) { return false; }
		if(!pStream->Serialize(&Distance)) { return false; }
		if(!pStream->Serialize(&RangeX)) { return false; }
		if(!pStream->Serialize(&RangeY)) { return false; }
		if(!pStream->Serialize(&CastTime)) { return false; }
		if(!pStream->Serialize(&RecastTime)) { return false; }
		if(!pStream->Serialize(&BonusStr)) { return false; }
		if(!pStream->Serialize(&BonusInt)) { return false; }
		if(!pStream->Serialize(&BonusMnd)) { return false; }
		if(!pStream->Serialize(&BonusVit)) { return false; }
		if(!pStream->Serialize(&VolatileHate)) { return false; }
		if(!pStream->Serialize(&AccumulateHate)) { return false; }
		if(!pStream->Serialize(&BuffId)) { return false; }

		return true;
	}

};

class SkillMaster
{

private:

	typedef TMap<u32, SkillItem> ItemMap;
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<SkillItem> GetAll() const;

	const SkillItem *Get(u32 Key, int32 SheetIndex = 0) const;

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef __SKILLMASTER_H__

#ifndef __SKILLTREEMASTER_H__
#define __SKILLTREEMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

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


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		if(!pStream->Serialize(&Job)) { return false; }
		if(!pStream->Serialize(&SkillId)) { return false; }
		if(!pStream->Serialize(&NeedLevel)) { return false; }
		if(!pStream->Serialize(&Cost)) { return false; }
		if(!pStream->Serialize(&NodeX)) { return false; }
		if(!pStream->Serialize(&NodeY)) { return false; }
		if(!pStream->Serialize(&ParentNode)) { return false; }

		return true;
	}

};

class SkillTreeMaster
{

private:

	typedef TMap<u32, SkillTreeItem> ItemMap;
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<SkillTreeItem> GetAll() const;

	const SkillTreeItem *Get(u32 Key, int32 SheetIndex = 0) const;

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef __SKILLTREEMASTER_H__

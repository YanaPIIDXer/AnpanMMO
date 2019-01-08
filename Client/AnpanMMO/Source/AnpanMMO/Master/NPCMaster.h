#ifndef __NPCMASTER_H__
#define __NPCMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct NPCItem
{

public:



	u32 ID;
	FString Name;
	u32 AreaId;
	float X;
	float Y;
	float Z;
	float Rotation;
	FString ScriptName;
	u32 AppearConditionId;
	u32 EraseConditionId;
	u32 ResourceId;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		std::string StrName;
		if(!pStream->Serialize(&StrName)) { return false; }
		Name = UTF8_TO_TCHAR(StrName.c_str());
		if(!pStream->Serialize(&AreaId)) { return false; }
		if(!pStream->Serialize(&X)) { return false; }
		if(!pStream->Serialize(&Y)) { return false; }
		if(!pStream->Serialize(&Z)) { return false; }
		if(!pStream->Serialize(&Rotation)) { return false; }
		std::string StrScriptName;
		if(!pStream->Serialize(&StrScriptName)) { return false; }
		ScriptName = UTF8_TO_TCHAR(StrScriptName.c_str());
		if(!pStream->Serialize(&AppearConditionId)) { return false; }
		if(!pStream->Serialize(&EraseConditionId)) { return false; }
		if(!pStream->Serialize(&ResourceId)) { return false; }

		return true;
	}

};

class NPCMaster
{

private:

	typedef TMap<u32, NPCItem> ItemMap;
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<NPCItem> GetAll() const;

	const NPCItem *Get(u32 Key, int32 SheetIndex = 0) const;

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef __NPCMASTER_H__

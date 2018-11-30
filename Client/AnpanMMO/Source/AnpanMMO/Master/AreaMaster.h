#ifndef __AREAMASTER_H__
#define __AREAMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct AreaItem
{

public:

	enum
	{
		NORMAL_AREA = 0,
		INSTANCE_AREA = 1,
	};


	u32 ID;
	FString Name;
	FString LevelName;
	u8 Type;
	u32 InstanceInfoId;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		std::string StrName;
		if(!pStream->Serialize(&StrName)) { return false; }
		Name = UTF8_TO_TCHAR(StrName.c_str());
		std::string StrLevelName;
		if(!pStream->Serialize(&StrLevelName)) { return false; }
		LevelName = UTF8_TO_TCHAR(StrLevelName.c_str());
		if(!pStream->Serialize(&Type)) { return false; }
		if(!pStream->Serialize(&InstanceInfoId)) { return false; }

		return true;
	}

};

class AreaMaster
{

private:

	typedef TMap<u32, AreaItem> ItemMap;

public:

	void Load();

	TArray<AreaItem> GetAll() const;

	const AreaItem *Get(u32 Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef __AREAMASTER_H__

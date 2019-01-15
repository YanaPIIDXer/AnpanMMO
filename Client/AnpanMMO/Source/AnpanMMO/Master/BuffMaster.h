#ifndef __BUFFMASTER_H__
#define __BUFFMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct BuffItem
{

public:

	enum
	{
		SPEEDUP = 0,
		REGENE = 1,
		POISON = 2,
		PARALYSIS = 3,
	};


	u32 ID;
	FString Name;
	u8 Type;
	u32 TimeMilliSec;
	float Value;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		std::string StrName;
		if(!pStream->Serialize(&StrName)) { return false; }
		Name = UTF8_TO_TCHAR(StrName.c_str());
		if(!pStream->Serialize(&Type)) { return false; }
		if(!pStream->Serialize(&TimeMilliSec)) { return false; }
		if(!pStream->Serialize(&Value)) { return false; }

		return true;
	}

};

class BuffMaster
{

private:

	typedef TMap<u32, BuffItem> ItemMap;
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<BuffItem> GetAll() const;

	const BuffItem *Get(u32 Key, int32 SheetIndex = 0) const;

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef __BUFFMASTER_H__

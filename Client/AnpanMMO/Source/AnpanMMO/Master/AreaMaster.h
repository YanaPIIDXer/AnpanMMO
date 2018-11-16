#ifndef __AREAMASTER_H__
#define __AREAMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct AreaItem
{

public:

	u32 ID;
	std::string Name;
	u32 AnpanMax;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		if(!pStream->Serialize(&Name)) { return false; }
		if(!pStream->Serialize(&AnpanMax)) { return false; }

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

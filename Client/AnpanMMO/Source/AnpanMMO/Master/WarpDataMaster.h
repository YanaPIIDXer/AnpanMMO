#ifndef __WARPDATAMASTER_H__
#define __WARPDATAMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct WarpDataItem
{

public:

	s32 AutoKey;
	u32 ID;
	u32 AreaId;
	float X;
	float Y;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&AutoKey)) { return false; }
		if(!pStream->Serialize(&ID)) { return false; }
		if(!pStream->Serialize(&AreaId)) { return false; }
		if(!pStream->Serialize(&X)) { return false; }
		if(!pStream->Serialize(&Y)) { return false; }

		return true;
	}

};

class WarpDataMaster
{

private:

	typedef TMap<s32, WarpDataItem> ItemMap;

public:

	void Load();

	TArray<WarpDataItem> GetAll() const;

	TArray<const WarpDataItem *> CollectItems(u32 Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef __WARPDATAMASTER_H__

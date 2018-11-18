#ifndef __WARPDATAMASTER_H__
#define __WARPDATAMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct WarpDataItem
{

public:

	u32 ID;
	u32 WarpDataId;
	u32 AreaId;
	float X;
	float Y;
	float Z;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&ID)) { return false; }
		if(!pStream->Serialize(&WarpDataId)) { return false; }
		if(!pStream->Serialize(&AreaId)) { return false; }
		if(!pStream->Serialize(&X)) { return false; }
		if(!pStream->Serialize(&Y)) { return false; }
		if(!pStream->Serialize(&Z)) { return false; }

		return true;
	}

};

class WarpDataMaster
{

private:

	typedef TMap<u32, WarpDataItem> ItemMap;

public:

	void Load();

	TArray<WarpDataItem> GetAll() const;

	const WarpDataItem *Get(u32 Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef __WARPDATAMASTER_H__

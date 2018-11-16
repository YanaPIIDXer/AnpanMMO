#ifndef __WARPPOINTMASTER_H__
#define __WARPPOINTMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct WarpPointItem
{

public:

	u32 Id;
	u32 AreaId;
	float X;
	float Y;
	u32 WarpDataId;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&Id)) { return false; }
		if(!pStream->Serialize(&AreaId)) { return false; }
		if(!pStream->Serialize(&X)) { return false; }
		if(!pStream->Serialize(&Y)) { return false; }
		if(!pStream->Serialize(&WarpDataId)) { return false; }

		return true;
	}

};

class WarpPointMaster
{

private:

	typedef TMap<u32, WarpPointItem> ItemMap;

public:

	void Load();

	TArray<WarpPointItem> GetAll() const;

	const WarpPointItem *Get(u32 Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef __WARPPOINTMASTER_H__

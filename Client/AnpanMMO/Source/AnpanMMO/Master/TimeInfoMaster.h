#ifndef __TIMEINFOMASTER_H__
#define __TIMEINFOMASTER_H__

#include "MemoryStream/MemoryStreamInterface.h"

struct TimeInfoItem
{

public:

	enum
	{
		MORNING = 0,
		AFTERNOON = 1,
		EVENING = 2,
		NIGHT = 3,
	};


	u32 Id;
	u8 TimeType;
	float LightAngle;
	float CloudSpeed;
	float CloudOpacity;
	float StarsBrightness;


	bool Serialize(MemoryStreamInterface *pStream)
	{
		if(!pStream->Serialize(&Id)) { return false; }
		if(!pStream->Serialize(&TimeType)) { return false; }
		if(!pStream->Serialize(&LightAngle)) { return false; }
		if(!pStream->Serialize(&CloudSpeed)) { return false; }
		if(!pStream->Serialize(&CloudOpacity)) { return false; }
		if(!pStream->Serialize(&StarsBrightness)) { return false; }

		return true;
	}

};

class TimeInfoMaster
{

private:

	typedef TMap<u32, TimeInfoItem> ItemMap;

public:

	void Load();

	TArray<TimeInfoItem> GetAll() const;

	const TimeInfoItem *Get(u32 Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef __TIMEINFOMASTER_H__

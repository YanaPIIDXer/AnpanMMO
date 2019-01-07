#ifndef __TIMEINFOMASTER_H__
#define __TIMEINFOMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

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


};

bool operator <(const TimeInfoItem &A, const TimeInfoItem &B);
bool operator >(const TimeInfoItem &A, const TimeInfoItem &B);

class TimeInfoMaster
{

private:

	typedef std::map<u32, TimeInfoItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const TimeInfoItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<TimeInfoItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __TIMEINFOMASTER_H__

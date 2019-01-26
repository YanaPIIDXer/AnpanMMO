#ifndef __BUFFMASTER_H__
#define __BUFFMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct BuffItem
{

public:

	enum
	{
		SPEEDUP = 0,
		AUTO_HEAL = 1,
		POISON = 2,
		PARALYSIS = 3,
	};


	u32 ID;
	std::string Name;
	u8 Type;
	u32 TimeMilliSec;
	float Value;


};

bool operator <(const BuffItem &A, const BuffItem &B);
bool operator >(const BuffItem &A, const BuffItem &B);

class BuffMaster
{

private:

	typedef std::map<u32, BuffItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const BuffItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<BuffItem> GetAllSheetItem(s32 SheetIndex) const;

	std::vector<BuffItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __BUFFMASTER_H__

#ifndef __ANPANAIMASTER_H__
#define __ANPANAIMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct AnpanAIItem
{

public:

	enum
	{
		WAIT = 0,
		APPROACH = 1,
		KEEP_DISTANCE = 2,
		USE_SKILL = 3,
		CHANGE_STAGE = 4,
	};


	s32 AutoKey;
	u8 StageNo;
	u8 Action;
	u32 Value;


};

bool operator <(const AnpanAIItem &A, const AnpanAIItem &B);
bool operator >(const AnpanAIItem &A, const AnpanAIItem &B);

class AnpanAIMaster
{

private:

	typedef std::map<u8, AnpanAIItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	std::vector<const AnpanAIItem *> CollectItems(u8 Key, s32 SheetIndex = 0) const;

	std::vector<AnpanAIItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __ANPANAIMASTER_H__

#ifndef __ANPANMASTER_H__
#define __ANPANMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct AnpanItem
{

public:



	u32 ID;
	s32 Hp;
	s32 Atk;
	s32 Def;
	s32 Exp;
	float Scale;
	u32 DropId;


};

bool operator <(const AnpanItem &A, const AnpanItem &B);
bool operator >(const AnpanItem &A, const AnpanItem &B);

class AnpanMaster
{

private:

	typedef std::map<u32, AnpanItem> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	const AnpanItem *GetItem(u32 Key, s32 SheetIndex = 0) const;

	std::vector<AnpanItem> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef __ANPANMASTER_H__

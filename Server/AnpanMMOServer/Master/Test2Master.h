#ifndef __TEST2MASTER_H__
#define __TEST2MASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct Test2Item
{

public:

	u32 ID;
	s32 Hp;
	s32 Mp;
	s32 Exp;


};

bool operator <(const Test2Item &A, const Test2Item &B);
bool operator >(const Test2Item &A, const Test2Item &B);

class Test2Master
{

private:

	typedef std::map<u32, Test2Item> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	const Test2Item *GetItem(u32 Key) const;

	std::vector<Test2Item> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __TEST2MASTER_H__

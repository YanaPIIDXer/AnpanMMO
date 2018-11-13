#ifndef __TEST3MASTER_H__
#define __TEST3MASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct Test3Item
{

public:

	u32 ID;
	s32 Hp;
	s32 Mp;
	s32 Exp;


};

bool operator <(const Test3Item &A, const Test3Item &B);
bool operator >(const Test3Item &A, const Test3Item &B);

class Test3Master
{

private:

	typedef std::map<u32, Test3Item> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	const Test3Item *GetItem(u32 Key) const;

	std::vector<Test3Item> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __TEST3MASTER_H__

#ifndef __TESTMASTER_H__
#define __TESTMASTER_H__

#include <map>
#include <vector>

class MySqlConnection;

struct TestItem
{

public:

	u32 ID;
	std::string Name;
	s32 Hp;
	s32 Mp;
	s32 Exp;


};

bool operator <(const TestItem &A, const TestItem &B);
bool operator >(const TestItem &A, const TestItem &B);

class TestMaster
{

private:

	typedef std::map<u32, TestItem> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	const TestItem *GetItem(u32 Key) const;

	std::vector<TestItem> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef __TESTMASTER_H__

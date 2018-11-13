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

// ソート用オペレータオーバーロード
bool operator <(const TestItem &A, const TestItem &B);
bool operator >(const TestItem &A, const TestItem &B);

class TestMaster
{

private:		// 別名定義.

	typedef std::map<u32, TestItem> ItemMap;

public:

	// 読み込み.
	bool Load(const MySqlConnection &Connection);

	// アイテム取得.
	const TestItem *GetItem(u32 Key) const;

	// 全取得.
	std::vector<TestItem> GetAll() const;

private:

	// アイテムマップ
	ItemMap Items;

};

#endif		// #ifndef __TESTMASTER_H__

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

// ソート用オペレータオーバーロード
bool operator <(const Test2Item &A, const Test2Item &B);
bool operator >(const Test2Item &A, const Test2Item &B);

class Test2Master
{

private:		// 別名定義.

	typedef std::map<u32, Test2Item> ItemMap;

public:

	// 読み込み.
	bool Load(const MySqlConnection &Connection);

	// アイテム取得.
	const Test2Item *GetItem(u32 Key) const;

	// 全取得.
	std::vector<Test2Item> GetAll() const;

private:

	// アイテムマップ
	ItemMap Items;

};

#endif		// #ifndef __TEST2MASTER_H__

﻿#ifndef $INCLUDE_GUARD$
#define $INCLUDE_GUARD$

#include <map>
#include <vector>

class MySqlConnection;

struct $ITEM_STRUCT_NAME$
{

public:

$ITEM_LIST$

};

// ソート用オペレータオーバーロード
bool operator <(const $ITEM_STRUCT_NAME$ &A, const $ITEM_STRUCT_NAME$ &B);
bool operator >(const $ITEM_STRUCT_NAME$ &A, const $ITEM_STRUCT_NAME$ &B);

class $CLASS_NAME$
{

private:		// 別名定義.

	typedef std::map<$KEY_TYPE$, $ITEM_STRUCT_NAME$> ItemMap;

public:

	// 読み込み.
	bool Load(const MySqlConnection &Connection);

	// アイテム取得.
	const $ITEM_STRUCT_NAME$ *GetItem($KEY_TYPE$ Key) const;

	// 全取得.
	std::vector<$ITEM_STRUCT_NAME$> GetAll() const;

private:

	// アイテムマップ
	ItemMap Items;

};

#endif		// #ifndef $INCLUDE_GUARD$

#ifndef $INCLUDE_GUARD$
#define $INCLUDE_GUARD$

#include <map>

class MySqlConnection;

struct $ITEM_STRUCT_NAME$
{

public:

$ITEM_LIST$

};

class $CLASS_NAME$
{

private:		// 別名定義.

	typedef std::map<$KEY_TYPE$, $ITEM_STRUCT_NAME$> ItemMap;

public:

	// 読み込み.
	void Load(const MySqlConnection &Connection);

	// アイテム取得.
	const $ITEM_STRUCT_NAME$ *GetItem($KEY_TYPE$ Key) const;

private:

	// アイテムマップ
	ItemMap Items;

};

#endif		// #ifndef $INCLUDE_GUARD$

#include "stdafx.h"
#include "$HEADER_FILE_NAME$"
#include "MySQL/MySqlConnection.h"

// 読み込み。
void $CLASS_NAME$::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from $MASTER_NAME$;");

	$ITEM_STRUCT_NAME$ BindItem;
$STRING_BIND$
$ITEM_BIND$
	Query.ExecuteQuery();
	while (Query.Fetch())
	{
		$ITEM_STRUCT_NAME$ Item;
$ITEM_FETCH$
		$APPEND_TO_MAP$
	}
}

// アイテム取得.
const $ITEM_STRUCT_NAME$ *$CLASS_NAME$::GetItem($KEY_TYPE$ Key) const
{
	ItemMap::const_iterator It = Items.find(Key);
	if (It == Items.end()) { return NULL; }
	return &It->second;
}

#include "stdafx.h"
#include "$HEADER_FILE_NAME$"
#include "MySQL/MySqlConnection.h"

bool $CLASS_NAME$::Load(const MySqlConnection &Connection)
{
	MySqlQuery Query = Connection.CreateQuery("select * from $MASTER_NAME$;");

	$ITEM_STRUCT_NAME$ BindItem;
$STRING_BIND$
$ITEM_BIND$
	if (!Query.ExecuteQuery()) { return false; }
	while (Query.Fetch())
	{
		$ITEM_STRUCT_NAME$ Item;
$ITEM_FETCH$
		$APPEND_TO_MAP$
	}

	return true;
}

$GET_KEY_FUNCTION$

std::vector<$ITEM_STRUCT_NAME$> $CLASS_NAME$::GetAll() const
{
	std::vector<$ITEM_STRUCT_NAME$> AllItem;
	for (ItemMap::const_iterator It = Items.begin(); It != Items.end(); ++It)
	{
		AllItem.push_back(It->second);
	}
	
	std::sort(AllItem.begin(), AllItem.end());
	return AllItem;
}

bool operator <(const $ITEM_STRUCT_NAME$ &A, const $ITEM_STRUCT_NAME$ &B)
{
	return (A.$KEY_NAME$ < B.$KEY_NAME$);
}

bool operator >(const $ITEM_STRUCT_NAME$ &A, const $ITEM_STRUCT_NAME$ &B)
{
	return (A.$KEY_NAME$ > B.$KEY_NAME$);
}

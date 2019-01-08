#ifndef $INCLUDE_GUARD$
#define $INCLUDE_GUARD$

#include <map>
#include <vector>

class MySqlConnection;

struct $ITEM_STRUCT_NAME$
{

public:

$ENUMS$

$ITEM_LIST$

};

bool operator <(const $ITEM_STRUCT_NAME$ &A, const $ITEM_STRUCT_NAME$ &B);
bool operator >(const $ITEM_STRUCT_NAME$ &A, const $ITEM_STRUCT_NAME$ &B);

class $CLASS_NAME$
{

private:

	typedef std::map<$KEY_TYPE$, $ITEM_STRUCT_NAME$> ItemMap;
	typedef std::map<int, ItemMap> SheetMap;

public:

	bool Load(const MySqlConnection &Connection);

	$GET_ITEN_FUNCTION_DECRARE$

	std::vector<$ITEM_STRUCT_NAME$> GetAll() const;

private:

	SheetMap Items;

};

#endif		// #ifndef $INCLUDE_GUARD$

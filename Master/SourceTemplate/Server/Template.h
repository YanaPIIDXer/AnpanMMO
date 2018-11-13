#ifndef $INCLUDE_GUARD$
#define $INCLUDE_GUARD$

#include <map>
#include <vector>

class MySqlConnection;

struct $ITEM_STRUCT_NAME$
{

public:

$ITEM_LIST$

};

bool operator <(const $ITEM_STRUCT_NAME$ &A, const $ITEM_STRUCT_NAME$ &B);
bool operator >(const $ITEM_STRUCT_NAME$ &A, const $ITEM_STRUCT_NAME$ &B);

class $CLASS_NAME$
{

private:

	typedef std::map<$KEY_TYPE$, $ITEM_STRUCT_NAME$> ItemMap;

public:

	bool Load(const MySqlConnection &Connection);

	const $ITEM_STRUCT_NAME$ *GetItem($KEY_TYPE$ Key) const;

	std::vector<$ITEM_STRUCT_NAME$> GetAll() const;

private:

	ItemMap Items;

};

#endif		// #ifndef $INCLUDE_GUARD$

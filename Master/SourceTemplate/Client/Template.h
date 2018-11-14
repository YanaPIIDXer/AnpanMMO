#ifndef $INCLUDE_GUARD$
#define $INCLUDE_GUARD$

#include "MemoryStream/MemoryStreamInterface.h"

struct $ITEM_STRUCT_NAME$
{

public:

$ITEM_LIST$

	bool Serialize(MemoryStreamInterface *pStream)
	{
$ITEM_SERIALIZE$
		return true;
	}

};

class $CLASS_NAME$
{

private:

	typedef TMap<$KEY_TYPE$, $ITEM_STRUCT_NAME$> ItemMap;

public:

	void Load();

	TArray<$ITEM_STRUCT_NAME$> GetAll() const;

	const $ITEM_STRUCT_NAME$ *Get($KEY_TYPE$ Key) const;

private:

	static const FString FileName;

	ItemMap Items;

};

#endif		// #ifndef $INCLUDE_GUARD$

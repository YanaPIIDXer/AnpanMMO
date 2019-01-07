#ifndef $INCLUDE_GUARD$
#define $INCLUDE_GUARD$

#include "MemoryStream/MemoryStreamInterface.h"

struct $ITEM_STRUCT_NAME$
{

public:

$ENUMS$

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
	typedef TMap<int32, ItemMap> SheetMap;

public:

	void Load();

	TArray<$ITEM_STRUCT_NAME$> GetAll() const;

	$GET_ITEM_FUNCTION_DECRARE$

private:

	static const FString FileName;

	SheetMap Items;

};

#endif		// #ifndef $INCLUDE_GUARD$

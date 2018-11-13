#ifndef $INCLUDE_GUARD$
#define $INCLUDE_GUARD$

struct $ITEM_STRUCT_NAME$
{

public:

$ITEM_LIST$

	bool Serialize(MemoryStramInterface *pStream)
	{
$ITEM_SERIALIZE$
		return true;
	}

};

#endif		// #ifndef $INCLUDE_GUARD$

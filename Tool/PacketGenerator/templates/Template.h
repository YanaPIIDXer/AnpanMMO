#ifndef $INCLUDE_GUARD$
#define $INCLUDE_GUARD$

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"
$INCLUDES$

class $CLASS_NAME$ $BASE_CLASS_NAME$
{
public:
	$GET_PACKET_ID_FUNCTION$

	$ENUMS$

	$MEMBERS$

	$CLASS_NAME$()
	{
	}

	$CONSTRUCTOR$

	bool Serialize(MemoryStreamInterface *pStream)
	{
		$SERIALIZE_MEMBERS$
		return true;
	}
};

#endif		// #ifndef $INCLUDE_GUARD$

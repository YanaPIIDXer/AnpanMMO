#ifndef __CHARACTERTYPE_H__
#define __CHARACTERTYPE_H__

#include "PacketBase.h"
#include "PacketID.h"
#include "MemoryStream/MemoryStreamInterface.h"


class CharacterType 
{
public:
	

	enum Type
	{
		Player,
		Enemy,
	};

	

	CharacterType()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __CHARACTERTYPE_H__

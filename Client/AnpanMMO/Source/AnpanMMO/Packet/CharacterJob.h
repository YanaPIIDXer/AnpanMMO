#ifndef __CHARACTERJOB_H__
#define __CHARACTERJOB_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


class CharacterJob 
{
public:
	

	enum Type
	{
		Fighter,
		Sorcerer,
		Healer,
		Lancer,
	};

	

	CharacterJob()
	{
	}

	

	bool Serialize(MemoryStreamInterface *pStream)
	{
		
		return true;
	}
};

#endif		// #ifndef __CHARACTERJOB_H__

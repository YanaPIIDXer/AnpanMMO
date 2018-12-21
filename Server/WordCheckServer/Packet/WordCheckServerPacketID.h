#ifndef __WORDCHECKSERVERPACKETID_H__
#define __WORDCHECKSERVERPACKETID_H__

class WordCheckPacketID
{

public:

	enum EID
	{
		WordCheckChatRequest = 0x80,
		WordCheckChatResult = 0x81,
		
	};
};

#endif		// #ifndef __WORDCHECKSERVERPACKETID_H__

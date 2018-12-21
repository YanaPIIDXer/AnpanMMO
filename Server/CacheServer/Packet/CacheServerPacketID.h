#ifndef __CACHESERVERPACKETID_H__
#define __CACHESERVERPACKETID_H__

class CachePacketID
{

public:

	enum EID
	{
		CacheLogInRequest = 0x40,
		CacheLogInResult = 0x41,
		CacheCreateCharacterRequest = 0x42,
		CacheCreateCharacterResult = 0x43,
		CacheCharacterDataRequest = 0x44,
		CacheCharacterDataResult = 0x45,
		CacheSkillListRequest = 0x46,
		CacheSkillListResponse = 0x47,
		CacheScriptFlagRequest = 0x48,
		CacheScriptFlagResponse = 0x49,
		CacheScriptFlagSaveRequest = 0x4A,
		CacheSaveSkillListRequest = 0x4B,
		CacheSaveSkillListResponse = 0x4C,
		CacheSkillTreeRequest = 0x4D,
		CacheSkillTreeResponse = 0x4E,
		CacheOpenSkillTree = 0x4F,
		CacheCharacterDataSave = 0x50,
		CacheGoldSave = 0x51,
		CacheItemListRequest = 0x52,
		CacheItemListResponse = 0x53,
		CacheItemCountChangeRequest = 0x54,
		CacheItemShortcutRequest = 0x55,
		CacheItemShortcutResponse = 0x56,
		CacheSaveItemShortcutRequest = 0x57,
		CacheSaveItemShortcutResponse = 0x58,
		CacheQuestDataRequest = 0x59,
		CacheQuestDataResponse = 0x5A,
		CacheSaveQuestDataRequest = 0x5B,
		CacheQuestRetireRequest = 0x5C,
		CacheSaveActiveQuestRequest = 0x5D,
		
	};
};

#endif		// #ifndef __CACHESERVERPACKETID_H__

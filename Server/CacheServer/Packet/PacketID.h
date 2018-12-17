#ifndef __PACKETID_H__
#define __PACKETID_H__

class PacketID
{

public:

	enum EID
	{
		AnpanList,
		SpawnAnpan,
		MoveAnpan,
		RotateAnpan,
		StopAnpan,
		Damage,
		Heal,
		CacheLogInRequest,
		CacheLogInResult,
		CacheCreateCharacterRequest,
		CacheCreateCharacterResult,
		CacheCharacterDataRequest,
		CacheCharacterDataResult,
		CacheSkillListRequest,
		CacheSkillListResponse,
		CacheScriptFlagRequest,
		CacheScriptFlagResponse,
		CacheScriptFlagSaveRequest,
		CacheSaveSkillListRequest,
		CacheSaveSkillListResponse,
		CacheSkillTreeRequest,
		CacheSkillTreeResponse,
		CacheOpenSkillTree,
		CacheCharacterDataSave,
		CacheGoldSave,
		CacheItemListRequest,
		CacheItemListResponse,
		CacheItemSubtractRequest,
		SendChat,
		ReceiveChat,
		GameReady,
		AreaMove,
		AreaMoveRequest,
		AreaMoveResponse,
		AddExp,
		LevelUp,
		ChangeGold,
		InstanceAreaTicketPublish,
		InstanceAreaTicketProcess,
		InstanceAreaTicketDiscard,
		SpawnInstanceAreaExitPoint,
		ItemList,
		ItemUse,
		ItemSubtract,
		ItemSubtractRequest,
		LogInRequest,
		LogInResult,
		CreateCharacterRequest,
		CreateCharacterResult,
		CharacterStatus,
		NoticeList,
		ReceiveNotice,
		NPCTalk,
		NPCTalkSelection,
		PartyCreateRequest,
		PartyCreateResult,
		PartyInviteRequest,
		PartyInviteResult,
		PartyInviteResponse,
		PartyJoin,
		PartyJoinMember,
		PartyExitRequest,
		PartyExitResult,
		PartyExit,
		PartyKickRequest,
		PartyKickResult,
		PartyKick,
		PartyDissolutionRequest,
		PartyDissolutionResult,
		PartyDissolution,
		Ping,
		PlayerList,
		SpawnPlayer,
		MovePlayer,
		ExitPlayer,
		RespawnRequest,
		PlayerRespawn,
		ScriptFlag,
		SkillUse,
		SkillUseFailed,
		SkillCast,
		SkillCastFinish,
		SkillActivate,
		SkillRecast,
		SkillList,
		SaveSkillListRequest,
		SaveSkillListResponse,
		SkillTreeData,
		SkillTreeOpenRequest,
		SkillTreeOpenResult,
		Time,
		TimeChange,
		WordCheckChatRequest,
		WordCheckChatResult,
		
	};
};

#endif		// #ifndef __PACKETID_H__

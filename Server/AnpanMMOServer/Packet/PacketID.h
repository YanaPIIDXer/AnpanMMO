#ifndef __PACKETID_H__
#define __PACKETID_H__

enum PacketID
{
	AnpanList,
	SpawnAnpan,
	MoveAnpan,
	RotateAnpan,
	StopAnpan,
	Damage,
	CacheLogInRequest,
	CacheLogInResult,
	CacheCreateCharacterRequest,
	CacheCreateCharacterResult,
	CacheCharacterDataRequest,
	CacheCharacterDataResult,
	CacheScriptFlagRequest,
	CacheScriptFlagResponse,
	CacheScriptFlagSaveRequest,
	CacheCharacterDataSave,
	SendChat,
	ReceiveChat,
	GameReady,
	AreaMove,
	AreaMoveRequest,
	AreaMoveResponse,
	AddExp,
	LevelUp,
	InstanceAreaTicketPublish,
	InstanceAreaTicketProcess,
	InstanceAreaTicketDiscard,
	SpawnInstanceAreaExitPoint,
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
	Time,
	TimeChange,
	WordCheckChatRequest,
	WordCheckChatResult,
	
};

#endif		// #ifndef __PACKETID_H__

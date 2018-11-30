#ifndef __PACKETID_H__
#define __PACKETID_H__

enum PacketID
{
	AnpanList,
	SpawnAnpan,
	MoveAnpan,
	RotateAnpan,
	StopAnpan,
	Attack,
	Damage,
	CacheLogInRequest,
	CacheLogInResult,
	CacheCreateCharacterRequest,
	CacheCreateCharacterResult,
	CacheCharacterDataRequest,
	CacheCharacterDataResult,
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
	PlayerList,
	SpawnPlayer,
	MovePlayer,
	ExitPlayer,
	RespawnRequest,
	PlayerRespawn,
	WordCheckChatRequest,
	WordCheckChatResult,
	
};

#endif		// #ifndef __PACKETID_H__

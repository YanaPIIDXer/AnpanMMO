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
	GameReady,
	AreaMove,
	AreaMoveRequest,
	AreaMoveResponse,
	AddExp,
	LevelUp,
	LogInRequest,
	LogInResult,
	CharacterStatus,
	CacheLogInRequest,
	CacheLogInResult,
	PlayerList,
	SpawnPlayer,
	MovePlayer,
	ExitPlayer,
	RespawnRequest,
	PlayerRespawn,
	
};

#endif		// #ifndef __PACKETID_H__

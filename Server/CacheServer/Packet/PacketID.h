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
	GameReady,
	AreaMove,
	AreaMoveRequest,
	AreaMoveResponse,
	AddExp,
	LevelUp,
	LogInRequest,
	LogInResult,
	CreateCharacterRequest,
	CreateCharacterResult,
	CharacterStatus,
	PlayerList,
	SpawnPlayer,
	MovePlayer,
	ExitPlayer,
	RespawnRequest,
	PlayerRespawn,
	
};

#endif		// #ifndef __PACKETID_H__

// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacterBase.h"

class MemoryStreamInterface;

/**
 * �v���C���[�Ǘ�.
 */
class ANPANMMO_API PlayerManager
{

private:		// �ʖ���`.

	typedef TWeakObjectPtr<APlayerCharacterBase> PlayerPtr;
	
public:

	// �R���X�g���N�^
	PlayerManager();

	// �f�X�g���N�^
	~PlayerManager() {}

	// World��ݒ�.
	void SetWorld(UWorld *pInWorld) { pWorld = pInWorld; }

	// �ǉ�.
	void Add(uint8 Uuid, APlayerCharacterBase *pPlayer);

	// �擾.
	APlayerCharacterBase *Get(uint32 Uuid) const;

	// ��������M.
	void OnRecvSpawn(MemoryStreamInterface *pStream);

	// ���X�g����M.
	void OnRecvList(MemoryStreamInterface *pStream);

	// �ړ�����M.
	void OnRecvMove(MemoryStreamInterface *pStream);

	// �ޏo����M.
	void OnRecvExit(MemoryStreamInterface *pStream);

private:

	// �v���C���[�}�b�v
	TMap<uint8, PlayerPtr> PlayerMap;

	// World
	TWeakObjectPtr<UWorld> pWorld;


	// �L�����N�^��Spawn
	void SpawnCharacter(uint32 Uuid, float X, float Y, float Rotation);

};

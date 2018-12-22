// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class AAnpan;
class MemoryStreamInterface;
class AnpanData;

/**
 * �A���p���Ǘ�.
 */
class ANPANMMO_API AnpanManager
{

private:		// �ʖ���`.

	typedef TWeakObjectPtr<AAnpan> AnpanPtr;

public:

	// �R���X�g���N�^
	AnpanManager();

	// �f�X�g���N�^
	~AnpanManager() {}

	// ���t���[���̏���.
	void Poll();

	// World���Z�b�g.
	void SetWorld(UWorld *pInWorld) { pWorld = pInWorld; }

	// �擾.
	AAnpan *Get(uint32 Uuid) const;

	// ���X�g����M����.
	bool OnRecvList(MemoryStreamInterface *pStream);

	// ��������M����.
	bool OnRecvSpawn(MemoryStreamInterface *pStream);

	// �ړ�����M�����B
	bool OnRecvMove(MemoryStreamInterface *pStream);

	// ��]����M�����B
	bool OnRecvRotate(MemoryStreamInterface *pStream);

	// ��~����M�����B
	bool OnRecvStop(MemoryStreamInterface *pStream);

	// �O���̃^�[�Q�b�g���擾.
	AAnpan *FindCenterTarget(float Distance);

	// ���Z�b�g.
	void Reset();

private:

	// �A���p���}�b�v
	TMap<uint32, AnpanPtr> AnpanMap;

	// World
	TWeakObjectPtr<UWorld> pWorld;


	// �A���p����Spawn
	void SpawnAnpan(const AnpanData &Data);

};

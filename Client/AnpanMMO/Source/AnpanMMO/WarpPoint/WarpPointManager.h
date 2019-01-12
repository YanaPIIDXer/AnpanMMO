// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class AWarpPoint;

/**
 * ���[�v�|�C���g�Ǘ��N���X
 */
class ANPANMMO_API WarpPointManager
{

private:		// �ʖ���`.

	typedef TWeakObjectPtr<AWarpPoint> WarpPointPtr;

public:

	// �R���X�g���N�^
	WarpPointManager();

	// �f�X�g���N�^
	~WarpPointManager() {}

	// World��ݒ�.
	void SetWorld(UWorld *pInWorld) { pWorld = pInWorld; }

	// Spawn
	void Spawn(uint32 AreaId);

	// ���[�v�|�C���g�h�c���琶��.
	void SpawnFromWarpPointId(uint32 WarpPointId);

	// ���Z�b�g
	void Reset();

private:

	// World
	TWeakObjectPtr<UWorld> pWorld;

	// ���[�v�|�C���g���X�g
	TArray<WarpPointPtr> WarpPoints;

};

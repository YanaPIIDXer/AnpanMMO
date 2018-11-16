// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WarpDataMaster.h"
#include "WarpPointMaster.h"

/**
 * �}�X�^�f�[�^
 */
class ANPANMMO_API MasterData : FNoncopyable
{

public:

	// �f�X�g���N�^
	~MasterData() {}

	// ���[�h
	void Load();

	// ���[�v�|�C���g�}�X�^���擾.
	const WarpPointMaster &GetWarpPointMaster() const { return WarpPoint; }

	// ���[�v�f�[�^�}�X�^���擾.
	const WarpDataMaster &GetWarpDataMaster() const { return WarpData; }

private:

	// ���[�v�|�C���g�}�X�^
	WarpPointMaster WarpPoint;

	// ���[�v�f�[�^�}�X�^
	WarpDataMaster WarpData;

	// =========== Singleton ============
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData();
	static MasterData Instance;
};

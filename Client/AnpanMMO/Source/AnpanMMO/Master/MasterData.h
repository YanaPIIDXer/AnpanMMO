// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AreaMaster.h"
#include "WarpDataMaster.h"
#include "WarpPointMaster.h"
#include "AnpanMaster.h"

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

	// �G���A�}�X�^���擾.
	const AreaMaster &GetAreaMaster() const { return Area; }

	// ���[�v�|�C���g�}�X�^���擾.
	const WarpPointMaster &GetWarpPointMaster() const { return WarpPoint; }

	// ���[�v�f�[�^�}�X�^���擾.
	const WarpDataMaster &GetWarpDataMaster() const { return WarpData; }

	// �A���p���}�X�^���擾.
	const AnpanMaster &GetAnpanMaster() const { return Anpan; }

private:

	// �G���A�}�X�^
	AreaMaster Area;

	// ���[�v�|�C���g�}�X�^
	WarpPointMaster WarpPoint;

	// ���[�v�f�[�^�}�X�^
	WarpDataMaster WarpData;

	// �A���p���}�X�^
	AnpanMaster Anpan;

	// =========== Singleton ============
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData();
	static MasterData Instance;
};

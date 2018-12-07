// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AreaMaster.h"
#include "WarpDataMaster.h"
#include "WarpPointMaster.h"
#include "AnpanMaster.h"
#include "TimeInfoMaster.h"
#include "NPCMaster.h"
#include "NPCResourceMaster.h"
#include "NPCConditionMaster.h"

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

	// ���ԏ��}�X�^���擾.
	const TimeInfoMaster &GetTimeInfoMaster() const { return TimeInfo; }

	// NPC�}�X�^���擾.
	const NPCMaster &GetNPCMaster() const { return NPC; }

	// NPC���\�[�X�}�X�^���擾.
	const NPCResourceMaster &GetNPCReseourceMaster() const { return NPCResource; }

	// NPC�R���f�B�V�����}�X�^���擾.
	const NPCConditionMaster &GetNPCConditionMaster() const { return NPCCondition; }

private:

	// �G���A�}�X�^
	AreaMaster Area;

	// ���[�v�|�C���g�}�X�^
	WarpPointMaster WarpPoint;

	// ���[�v�f�[�^�}�X�^
	WarpDataMaster WarpData;

	// �A���p���}�X�^
	AnpanMaster Anpan;

	// ���ԏ��}�X�^
	TimeInfoMaster TimeInfo;

	// NPC�}�X�^
	NPCMaster NPC;

	// NPC���\�[�X�}�X�^
	NPCResourceMaster NPCResource;

	// NPC�R���f�B�V�����}�X�^
	NPCConditionMaster NPCCondition;

	// =========== Singleton ============
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData();
	static MasterData Instance;
};

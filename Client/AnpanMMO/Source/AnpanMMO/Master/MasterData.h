// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

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
#include "SkillMaster.h"
#include "SkillTreeMaster.h"
#include "ItemMaster.h"
#include "QuestMaster.h"
#include "QuestStageMaster.h"
#include "QuestRewardMaster.h"
#include "EquipMaster.h"
#include "BuffMaster.h"

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

	// �X�L���}�X�^�擾.
	const SkillMaster &GetSkillMaster() const { return Skill; }

	// �X�L���c���[�}�X�^�擾.
	const SkillTreeMaster &GetSkillTreeMaster() const { return SkillTree; }

	// �A�C�e���}�X�^�擾.
	const ItemMaster &GetItemMaster() const { return Item; }

	// �N�G�X�g�}�X�^�擾.
	const QuestMaster &GetQuestMaster() const { return Quest; }

	// �N�G�X�g�X�e�[�W�}�X�^�擾.
	const QuestStageMaster &GetQuestStageMaster() const { return QuestStage; }

	// �N�G�X�g��V�}�X�^�擾.
	const QuestRewardMaster &GetQuestRewardMaster() const { return QuestReward; }

	// �����}�X�^�擾.
	const EquipMaster &GetEquipMaster() const { return Equip; }

	// �o�t�}�X�^�擾.
	const BuffMaster &GetBuffMaster() const { return Buff; }

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

	// �X�L���}�X�^
	SkillMaster Skill;

	// �X�L���c���[�}�X�^
	SkillTreeMaster SkillTree;

	// �A�C�e���}�X�^
	ItemMaster Item;

	// �N�G�X�g�}�X�^
	QuestMaster Quest;

	// �N�G�X�g�X�e�[�W�}�X�^
	QuestStageMaster QuestStage;

	// �N�G�X�g��V�}�X�^
	QuestRewardMaster QuestReward;

	// �����}�X�^
	EquipMaster Equip;

	// �o�t�}�X�^
	BuffMaster Buff;

	// =========== Singleton ============
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData();
	static MasterData Instance;
};

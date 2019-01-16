/**
 * @file MasterData.h
 * @brief �}�X�^�f�[�^�N���X
 * @author YanaP
 */
#ifndef __MASTERDATA_H__
#define __MASTERDATA_H__

#include "AreaMaster.h"
#include "WarpDataMaster.h"
#include "AnpanMaster.h"
#include "AnpanPopAreaMaster.h"
#include "AnpanPopDataMaster.h"
#include "InstanceInfoMaster.h"
#include "TimeInfoMaster.h"
#include "NPCMaster.h"
#include "SkillMaster.h"
#include "SkillTreeMaster.h"
#include "ItemMaster.h"
#include "ItemDropMaster.h"
#include "QuestMaster.h"
#include "QuestStageMaster.h"
#include "QuestRewardMaster.h"
#include "LevelMaster.h"
#include "EquipMaster.h"
#include "BuffMaster.h"

/**
 * @class MasterData
 * @brief �}�X�^�f�[�^�N���X
 * @detail �V���O���g���N���X
 */
class MasterData : public noncopyable
{

public:

	/**
	 * @fn bool Read()
	 * @brief �ǂݍ���
	 * @return ����������true��Ԃ�
	 */
	bool Read();

	/**
	 * @fn const AreaMaster &GetAreaMaster()
	 * @brief �G���A�}�X�^�擾
	 * @return �G���A�}�X�^
	 */
	const AreaMaster &GetAreaMaster() { return Area; }

	/**
	 * @fn const WarpDataMaster &GetWarpDataMaster()
	 * @brief ���[�v�f�[�^�}�X�^�擾
	 * @return ���[�v�f�[�^�}�X�^
	 */
	const WarpDataMaster &GetWarpDataMaster() { return WarpData; }

	/**
	 * @fn const AnpanMaster &GetAnpanMaster()
	 * @brief �A���p���}�X�^�擾
	 * @return �A���p���}�X�^
	 */
	const AnpanMaster &GetAnpanMaster() { return Anpan; }

	/**
	 * @fn const AnpanPopAreaMaster &GetAnpanPopAreaMaster()
	 * @brief �A���p���|�b�v�G���A�}�X�^�擾
	 * @return �A���p���|�b�v�G���A�}�X�^
	 */
	const AnpanPopAreaMaster &GetAnpanPopAreaMaster() { return AnpanPopArea; }

	/**
	 * @fn const AnpanPopDataMaster &GetAnpanPopDataMaster()
	 * @brief �A���p���|�b�v�f�[�^�}�X�^�擾
	 * @return �A���p���|�b�v�f�[�^�}�X�^
	 */
	const AnpanPopDataMaster &GetAnpanPopDataMaster() { return AnpanPopData; }

	/**
	 * @fn const InstanceInfoMaster &GetInstanceInfoMaster()
	 * @brief �C���X�^���X�G���A���}�X�^�擾
	 * @return �C���X�^���X�G���A���}�X�^
	 */
	const InstanceInfoMaster &GetInstanceInfoMaster() { return InstanceInfo; }

	/**
	 * @fn const TimeInfoMaster &GetTimeInfoMaster()
	 * @brief ���ԏ��}�X�^�擾
	 * @return ���ԏ��}�X�^
	 */
	const TimeInfoMaster &GetTimeInfoMaster() { return TimeInfo; }

	/**
	 * @fn const NPCMaster &GetNPCMaster()
	 * @brief �m�o�b�}�X�^�擾
	 * @return �m�o�b�}�X�^
	 */
	const NPCMaster &GetNPCMaster() { return NPC; }

	/**
	 * @fn const SkillMaster &GetSkillMaster()
	 * @brief �X�L���}�X�^�擾
	 * @return �X�L���}�X�^
	 */
	const SkillMaster &GetSkillMaster() { return Skill; }

	/**
	 * @fn const SkillTreeMaster &GetSkillTreeMaster()
	 * @brief �X�L���c���[�}�X�^�擾
	 * @return �X�L���c���[�}�X�^
	 */
	const SkillTreeMaster &GetSkillTreeMaster() { return SkillTree; }

	/**
	 * @fn const ItemMaster &GetItemMaster()
	 * @brief �A�C�e���}�X�^�擾
	 * @return �A�C�e���}�X�^
	 */
	const ItemMaster &GetItemMaster() { return Item; }

	/**
	 * @fn const ItemDropMaster &GetItemDropMaster()
	 * @brief �A�C�e���h���b�v�}�X�^�擾
	 * @return �A�C�e���h���b�v�}�X�^
	 */
	const ItemDropMaster &GetItemDropMaster() { return ItemDrop; }

	/**
	 * @fn const QuestMaster &GetQuestMaster()
	 * @brief �N�G�X�g�}�X�^�擾
	 * @return �N�G�X�g�}�X�^
	 */
	const QuestMaster &GetQuestMaster() { return Quest; }

	/**
	 * @fn const QuestStageMaster &GetQuestStageMaster()
	 * @brief �N�G�X�g�X�e�[�W�}�X�^�擾
	 * @return �N�G�X�g�X�e�[�W�}�X�^
	 */
	const QuestStageMaster &GetQuestStageMaster() { return QuestStage; }

	/**
	 * @fn const QuestRewardMaster &GetQuestRewardMaster()
	 * @brief �N�G�X�g��V�}�X�^�擾
	 * @return �N�G�X�g��V�}�X�^
	 */
	const QuestRewardMaster &GetQuestRewardMaster() { return QuestReward; }

	/**
	 * @fn const LevelMaster &GetLevelMaster()
	 * @brief ���x���}�X�^�擾
	 * @return ���x���}�X�^
	 */
	const LevelMaster &GetLevelMaster() { return Level; }

	/**
	 * @fn const EquipMaster &GetEquipMaster()
	 * @brief �����}�X�^�擾
	 * @return �����}�X�^
	 */
	const EquipMaster &GetEquipMaster() { return Equip; }

	/**
	 * @fn const BuffMaster &GetBuffMaster()
	 * @brief �o�t�}�X�^�擾
	 * @return �o�t�}�X�^
	 */
	const BuffMaster &GetBuffMaster() { return Buff; }

private:

	// DB�z�X�g
	static const char *DBHost;

	// DB��.
	static const char *DBName;

	// DB�̃��[�U���Ƃ��L�q�����t�@�C����.
	static const std::string DBDataFileName;

	// �G���A�}�X�^
	AreaMaster Area;

	// ���[�v�f�[�^�}�X�^
	WarpDataMaster WarpData;

	// �A���p���}�X�^
	AnpanMaster Anpan;

	// �A���p���|�b�v�G���A�}�X�^
	AnpanPopAreaMaster AnpanPopArea;

	// �A���p���|�b�v�f�[�^�}�X�^
	AnpanPopDataMaster AnpanPopData;

	// �C���X�^���X�}�b�v���}�X�^
	InstanceInfoMaster InstanceInfo;

	// ���ԏ��}�X�^
	TimeInfoMaster TimeInfo;

	// NPC�}�X�^
	NPCMaster NPC;

	// �X�L���}�X�^
	SkillMaster Skill;

	// �X�L���c���[�}�X�^
	SkillTreeMaster SkillTree;

	// �A�C�e���}�X�^
	ItemMaster Item;

	// �A�C�e���h���b�v�}�X�^
	ItemDropMaster ItemDrop;

	// �N�G�X�g�}�X�^
	QuestMaster Quest;

	// �N�G�X�g�X�e�[�W�}�X�^
	QuestStageMaster QuestStage;

	// �N�G�X�g��V�}�X�^
	QuestRewardMaster QuestReward;

	// ���x���}�X�^
	LevelMaster Level;

	// �����}�X�^
	EquipMaster Equip;

	// �o�t�}�X�^
	BuffMaster Buff;

	// ======= Singleton ==========
public:

	/**
	 * @fn static MasterData &GetInstance()
	 * @brief �C���X�^���X�擾
	 * @return �V���O���g���C���X�^���X
	 */
	static MasterData &GetInstance() { return Instance; }

private:

	MasterData() {}
	static MasterData Instance;

};

#endif		// #ifndef __MASTERDATA_H__

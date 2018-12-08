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

/**
 * �}�X�^�f�[�^�N���X
 */
class MasterData : public noncopyable
{

public:

	// �ǂݍ���
	bool Read();

	// �G���A�}�X�^�擾.
	const AreaMaster &GetAreaMaster() { return Area; }

	// ���[�v�f�[�^�}�X�^�擾.
	const WarpDataMaster &GetWarpDataMaster() { return WarpData; }

	// �A���p���}�X�^�擾.
	const AnpanMaster &GetAnpanMaster() { return Anpan; }

	// �A���p���|�b�v�G���A�}�X�^�擾.
	const AnpanPopAreaMaster &GetAnpanPopAreaMaster() { return AnpanPopArea; }

	// �A���p���|�b�v�f�[�^�}�X�^�擾.
	const AnpanPopDataMaster &GetAnpanPopDataMaster() { return AnpanPopData; }

	// �C���X�^���X�}�b�v���}�X�^�擾.
	const InstanceInfoMaster &GetInstanceInfoMaster() { return InstanceInfo; }

	// ���ԏ��}�X�^�擾.
	const TimeInfoMaster &GetTimeInfoMaster() { return TimeInfo; }

	// NPC�}�X�^���擾.
	const NPCMaster &GetNPCMaster() { return NPC; }

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

	// ======= Singleton ==========
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData() {}
	static MasterData Instance;

};

#endif		// #ifndef __MASTERDATA_H__

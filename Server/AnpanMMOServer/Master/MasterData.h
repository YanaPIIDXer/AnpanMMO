#ifndef __MASTERDATA_H__
#define __MASTERDATA_H__

#include "AreaMaster.h"
#include "WarpDataMaster.h"

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

	// ======= Singleton ==========
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData() {}
	static MasterData Instance;

};

#endif		// #ifndef __MASTERDATA_H__

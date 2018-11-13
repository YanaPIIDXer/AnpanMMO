#ifndef __MASTERDATA_H__
#define __MASTERDATA_H__

/**
 * �}�X�^�f�[�^�N���X
 */
class MasterData : public noncopyable
{

public:

	// �ǂݍ���
	bool Read();

private:

	// DB�z�X�g
	static const char *DBHost;

	// DB��.
	static const char *DBName;

	// DB�̃��[�U���Ƃ��L�q�����t�@�C����.
	static const std::string DBDataFileName;

	// ======= Singleton ==========
public:

	static MasterData &GetInstance() { return Instance; }

private:

	MasterData() {}
	static MasterData Instance;

};

#endif		// #ifndef __MASTERDATA_H__

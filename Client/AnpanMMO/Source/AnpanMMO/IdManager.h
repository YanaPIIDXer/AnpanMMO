#ifndef __IDMANAGER_H__
#define __IDMANAGER_H__

#include <string>

/**
 * ID�̃��[�J���Ǘ�.
 */
class IdManager
{

public:

	// �R���X�g���N�^
	IdManager(const std::string &InFilePath);

	// �f�X�g���N�^
	~IdManager() {}

	// ID�擾.
	std::string GetId();

private:

	// ID�̃L���b�V��.
	std::string IdCache;

	// �t�@�C���p�X
	std::string FilePath;

	// �t�@�C����.
	static const std::string FileName;

	// ID�̒���
	static const int IdLength;


	// ID�����[�h
	bool LoadId(std::string &OutId);

	// ID�𐶐�.
	void GenerateId(std::string &OutId);

};

#endif		// #ifndef __IDMANAGER_H__

#ifndef __WORDCHECKER_H__
#define __WORDCHECKER_H__

#include "Master/NGWordMaster.h"

/**
 * ���[�h�`�F�b�N�N���X
 */
class WordChecker
{

public:

	// �f�X�g���N�^
	~WordChecker() {}

	// �}�X�^�̓ǂݍ���
	bool LoadMaster();

private:

	// �}�X�^�ǂݍ��ݏ��t�@�C����.
	static const std::string MasterDBInfoFileName;

	// NG���[�h�}�X�^
	NGWordMaster NGWords;

	// ========== Singleton ==========

public:

	static WordChecker &GetInstance() { return Instance; }

private:

	WordChecker() {}
	static WordChecker Instance;

};

#endif		// #ifndef __WORDCHECKER_H__

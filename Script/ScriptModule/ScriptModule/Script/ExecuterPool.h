/**
 * @file ExecuterPool.h
 * @brief �X�N���v�g���s�I�u�W�F�N�g�v�[��
 * @author YanaP
 */
#ifndef __EXECUTERPOOL_H__
#define __EXECUTERPOOL_H__

#include <map>

class ScriptExecuterBase;

/**
 * @class ExecuterPool
 * @brief �X�N���v�g���s�I�u�W�F�N�g�v�[��
 * @details �N���X�̃����o�֐����o�C���h�o���Ȃ��֌W�ō��ꂽ�B
 *			ID�ƃX�N���v�g���s�I�u�W�F�N�g��R�t���A
 *			�X�N���v�g����C++���̊֐����Ăяo���ۂ͈�����ID��n���悤�ɂ���B
 *			�i�|�C���^�̂悤�Ȃ��́j
 *			�V���O���g���N���X
 */
class ExecuterPool
{

public:

	/**
	 * @brief �f�X�g���N�^
	 */
	~ExecuterPool() {}

	/**
	 * @fn long Register(ScriptExecuterBase *pExecuter)
	 * @brief �o�^
	 * @param[in] �X�N���v�g���s�N���X�ւ̃|�C���^
	 * @return �h�c
	 */
	long Register(ScriptExecuterBase *pExecuter);

	/*
	 * @fn ScriptExecuterBase *Get(long Id)
	 * @brief �擾
	 * @param[in] Id ID
	 * @return �X�N���v�g���s�N���X�ւ̃|�C���^
	 */
	ScriptExecuterBase *Get(long Id);

	/**
	 * @fn void Remove(long Id)
	 * @brief ����
	 * @param[in] Id ID
	 */
	void Remove(long Id);

private:

	// �v�[��
	std::map<long, ScriptExecuterBase *> Pool;

	// ���Ɋ���U����ID
	long NextId;

	// ========== Singleton ============
public:

	/**
	 * @fn static ExecuterPool &GetInstance()
	 * @brief �V���O���g���C���X�^���X���擾
	 * @return �C���X�^���X
	 */
	static ExecuterPool &GetInstance() { return Instance; }

private:

	ExecuterPool();
	static ExecuterPool Instance;

};

#endif		// #ifndef __EXECUTERPOOL_H__

#ifndef __EXECUTERPOOL_H__
#define __EXECUTERPOOL_H__

#include <map>

class ScriptExecuterBase;

/**
 * �X�N���v�g���s�I�u�W�F�N�g�v�[��
 * �N���X�̃����o�֐����o�C���h�o���Ȃ��֌W�ō��ꂽ�B
 * ID�ƃX�N���v�g���s�I�u�W�F�N�g��R�t���A
 * �X�N���v�g����C++���̊֐����Ăяo���ۂ͈�����ID��n���悤�ɂ���B
 * �i�|�C���^�̂悤�Ȃ��́j
 */
class ExecuterPool
{

public:

	// �f�X�g���N�^
	~ExecuterPool() {}

	// �o�^.
	long Register(ScriptExecuterBase *pExecuter);

	// �擾.
	ScriptExecuterBase *Get(long Id);

	// ����.
	void Remove(long Id);

private:

	// �v�[��
	std::map<long, ScriptExecuterBase *> Pool;

	// ���Ɋ���U����ID
	long NextId;

	// ========== Singleton ============
public:

	static ExecuterPool &GetInstance() { return Instance; }

private:

	ExecuterPool();
	static ExecuterPool Instance;

};

#endif		// #ifndef __EXECUTERPOOL_H__

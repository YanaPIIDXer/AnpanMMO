#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "ScriptExecuterBase.h"
#include <vector>
#include <map>

/**
 * �X�N���v�g���s�N���X
 */
class ScriptExecuter : public ScriptExecuterBase
{

public:

	// �R���X�g���N�^
	ScriptExecuter();

	// �f�X�g���N�^
	virtual ~ScriptExecuter() {}

	// ���b�Z�[�W�\���B
	virtual void ShowMessage_Impl(const std::string &Message);

	// �I�������v�b�V��
	virtual void PushSelection_Impl(const std::string &Message);

	// �I������\��.
	virtual void ShowSelection_Impl();
	
	// �t���O���Z�b�g
	virtual void SetFlag(const char *pFlagName) { FlagMap[pFlagName] = true; }

	// �t���O���擾.
	virtual bool GetFlag(const char *pFlagName) { return FlagMap[pFlagName]; }

protected:

	// ���s�G���[
	virtual void OnExecuteError(const std::string &Message);

	// �I�������B
	virtual void OnFinished();

	// �f�o�b�O���b�Z�[�W�\��.
	virtual void ShowDebugMessage(const std::string &Message);

private:

	// �I�������X�g
	std::string Selections[10];

	// �I�����̐��B
	int SelectionCount;

	// �t���O�}�b�v
	std::map<const char*, bool> FlagMap;

};

#endif		// #ifndef __SCRIPTEXECUTER_H__

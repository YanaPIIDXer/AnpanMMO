#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "Include/ScriptExecuterBase.h"
#include <vector>

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

protected:

	// ���s�G���[
	virtual void OnExecuteError(const std::string &Message);

private:

	// �I�������X�g
	std::vector<std::string> Selections;

};

#endif		// #ifndef __SCRIPTEXECUTER_H__

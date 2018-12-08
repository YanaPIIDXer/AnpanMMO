#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "ScriptExecuterBase.h"

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

	// ���b�Z�[�W��\��.
	virtual void ShowMessage_Impl(const std::string &Message) {}

	// �I�������v�b�V�����ꂽ�B
	virtual void PushSelection_Impl(const std::string &Message) {}

	// �I�����\��.
	virtual void ShowSelection_Impl() {}

	// �t���O���Z�b�g
	virtual void SetFlag(const char *pFlagName);

	// �t���O���擾.
	virtual bool GetFlag(const char *pFlagName);

protected:

	// ���s�G���[
	virtual void OnExecuteError(const std::string &ErrorMessage);

	// �������I�������B
	virtual void OnFinished() {}

	// �f�o�b�O���b�Z�[�W��\��.
	virtual void ShowDebugMessage(const std::string &Message);

	// �T�[�o���[�h���H
	virtual bool IsServer() const { return true; }


private:

};

#endif		// #ifndef __SCRIPTEXECUTER_H_

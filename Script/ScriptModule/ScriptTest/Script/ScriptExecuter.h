#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "Include/ScriptExecuterBase.h"

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

private:

};

#endif		// #ifndef __SCRIPTEXECUTER_H__

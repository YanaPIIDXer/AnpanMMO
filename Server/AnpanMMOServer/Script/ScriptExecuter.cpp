#include "stdafx.h"
#include "ScriptExecuter.h"
#include "Client.h"

// �R���X�g���N�^
ScriptExecuter::ScriptExecuter()
{
}

// �t���O���Z�b�g�B
void ScriptExecuter::SetFlag(int Flag)
{
	pClient->SetScriptFlag(Flag);
}

// �t���O���擾.
bool ScriptExecuter::GetFlag(int Flag)
{
	return pClient->GetScriptFlagManager().Get(Flag);
}


// ���s�G���[
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	std::cout << "Script Error:" << ErrorMessage << std::endl;
}

// �f�o�b�O���b�Z�[�W��\��.
void ScriptExecuter::ShowDebugMessage(const std::string &Message)
{
	std::cout << "Script Debug:" << Message << std::endl;
}

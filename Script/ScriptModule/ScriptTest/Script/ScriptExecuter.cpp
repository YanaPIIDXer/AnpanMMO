#include "ScriptExecuter.h"
#include <iostream>
#include <string>
#include <stdio.h>

// �R���X�g���N�^
ScriptExecuter::ScriptExecuter()
{
}

// ���b�Z�[�W�\��.
void ScriptExecuter::ShowMessage_Impl(const std::string &Message)
{
	std::cout << Message << std::endl;
	while (getchar() != '\n');
	Resume();
}


// ���s�G���[
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	std::cout << ErrorMessage << std::endl;
}

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

// �I�������v�b�V��
void ScriptExecuter::PushSelection_Impl(const std::string &Message)
{
	Selections.push_back(Message);
}

// �I������\��.
void ScriptExecuter::ShowSelection_Impl()
{
	for (unsigned int i = 0; i < Selections.size(); i++)
	{
		std::cout << (i + 1) << ":" << Selections[i] << std::endl;
	}
	std::cout << "Select:";
	char Ch = getchar();
	while ((Ch - '0') < 1 || (Ch - '0') > Selections.size())
	{
		std::cout << "Select:";
		Ch = getchar();
	}
	int Index = (Ch - '0') - 1;
	OnSelectedSelection(Index);
}


// ���s�G���[
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	std::cout << ErrorMessage << std::endl;
}

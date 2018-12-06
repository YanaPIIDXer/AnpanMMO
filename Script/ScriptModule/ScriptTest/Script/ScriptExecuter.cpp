#include "ScriptExecuter.h"
#include <iostream>
#include <string>
#include <stdio.h>

// �R���X�g���N�^
ScriptExecuter::ScriptExecuter()
	: SelectionCount(0)
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
	Selections[SelectionCount] = Message;
	SelectionCount++;
}

// �I������\��.
void ScriptExecuter::ShowSelection_Impl()
{
	for (int i = 0; i < SelectionCount; i++)
	{
		std::cout << (i + 1) << ":" << Selections[i] << std::endl;
	}
	std::cout << "Select:";
	char Ch = getchar();
	while ((Ch - '0') < 1 || (Ch - '0') > SelectionCount)
	{
		std::cout << "Select:";
		Ch = getchar();
	}
	int Index = (Ch - '0') - 1;
	OnSelectedSelection(Index);
	SelectionCount = 0;
}


// ���s�G���[
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	std::cout << ErrorMessage << std::endl;
}

// �I�������B
void ScriptExecuter::OnFinished()
{
	std::cout << "OnFinished" << std::endl;
}

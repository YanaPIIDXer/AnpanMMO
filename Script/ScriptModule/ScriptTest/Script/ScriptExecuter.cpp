#include "ScriptExecuter.h"
#include <iostream>
#include <string>
#include <stdio.h>

// コンストラクタ
ScriptExecuter::ScriptExecuter()
{
}

// メッセージ表示.
void ScriptExecuter::ShowMessage_Impl(const std::string &Message)
{
	std::cout << Message << std::endl;
	while (getchar() != '\n');
	Resume();
}

// 選択肢をプッシュ
void ScriptExecuter::PushSelection_Impl(const std::string &Message)
{
	Selections.push_back(Message);
}

// 選択肢を表示.
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


// 実行エラー
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	std::cout << ErrorMessage << std::endl;
}

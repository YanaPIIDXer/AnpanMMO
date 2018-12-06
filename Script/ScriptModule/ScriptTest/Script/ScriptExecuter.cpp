#include "ScriptExecuter.h"
#include <iostream>
#include <string>
#include <stdio.h>

// コンストラクタ
ScriptExecuter::ScriptExecuter()
	: SelectionCount(0)
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
	Selections[SelectionCount] = Message;
	SelectionCount++;
}

// 選択肢を表示.
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


// 実行エラー
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	std::cout << ErrorMessage << std::endl;
}

// 終了した。
void ScriptExecuter::OnFinished()
{
	std::cout << "OnFinished" << std::endl;
}

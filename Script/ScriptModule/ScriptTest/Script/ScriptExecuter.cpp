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


// 実行エラー
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	std::cout << ErrorMessage << std::endl;
}

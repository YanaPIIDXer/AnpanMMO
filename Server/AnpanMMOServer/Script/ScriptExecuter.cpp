#include "stdafx.h"
#include "ScriptExecuter.h"

// コンストラクタ
ScriptExecuter::ScriptExecuter()
{
}

// フラグをセット。
void ScriptExecuter::SetFlag(const char *pFlagName)
{

}

// フラグを取得.
bool ScriptExecuter::GetFlag(const char *pFlagName)
{
	return false;
}


// 実行エラー
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	std::cout << "Script Error:" << ErrorMessage << std::endl;
}

// デバッグメッセージを表示.
void ScriptExecuter::ShowDebugMessage(const std::string &Message)
{
	std::cout << "Script Debug:" << Message << std::endl;
}

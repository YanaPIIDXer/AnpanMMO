#include "stdafx.h"
#include "ScriptExecuter.h"
#include "Client.h"

// コンストラクタ
ScriptExecuter::ScriptExecuter()
{
}

// フラグをセット。
void ScriptExecuter::SetFlag(int Flag)
{
	pClient->SetScriptFlag(Flag);
}

// フラグを取得.
bool ScriptExecuter::GetFlag(int Flag)
{
	return pClient->GetScriptFlagManager().Get(Flag);
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

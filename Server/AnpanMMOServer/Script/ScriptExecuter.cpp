#include "stdafx.h"
#include "ScriptExecuter.h"
#include "Client.h"
#include <fstream>

// コンストラクタ
ScriptExecuter::ScriptExecuter()
{
}

// 読み込んで実行.
void ScriptExecuter::LoadAndRun(const std::string &FileName)
{
	std::string FilePath = "../../Script/Scripts/" + FileName + ".lua";
	std::ifstream FileStream(FilePath);
	if (!FileStream)
	{
		OnExecuteError("ScriptFile:" + FileName + " Load Failed...");
		return;
	}

	std::string Code = "";
	while (!FileStream.eof())
	{
		std::string Line;
		FileStream >> Line;
		Code += Line;
	}

	// BOMを無視する。
	Code = Code.substr(3);
	ExecuteScript(Code.c_str());
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

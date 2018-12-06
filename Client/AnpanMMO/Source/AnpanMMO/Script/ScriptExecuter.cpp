// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ScriptExecuter.h"

// コンストラクタ
ScriptExecuter::ScriptExecuter()
{
}

// メッセージを表示.
void ScriptExecuter::ShowMessage_Impl(const std::string &Message)
{
	UE_LOG(LogTemp, Log, TEXT("Message:%s"), Message.c_str());
}

// 選択肢をプッシュ.
void ScriptExecuter::PushSelection_Impl(const std::string &Message)
{
}

// 選択肢を表示.
void ScriptExecuter::ShowSelection_Impl()
{
	// 実験中は問答無用でインデックス０を選択。
	OnSelectedSelection(0);
}

// フラグをセット
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
	UE_LOG(LogTemp, Log, TEXT("ScriptError:%s"), ErrorMessage.c_str());
}

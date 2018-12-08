// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ScriptExecuter.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"
#include "Active/ActiveGameMode.h"

// コンストラクタ
ScriptExecuter::ScriptExecuter()
{
}

// スクリプトを実行.
void ScriptExecuter::RunScript(const FString &FileName)
{
	FString Path = Config::GetScriptDirectory() + "\\" + FileName + ".lua";

	IPlatformFile &File = FPlatformFileManager::Get().GetPlatformFile();
	IFileHandle *pFileHandle = File.OpenRead(*Path);
	if (pFileHandle == nullptr)
	{
		FString ErrorMsg = "ScriptFile:" + FileName + " Load Failed...";
		OnExecuteError(TCHAR_TO_ANSI(*ErrorMsg));
		return;
	}
	int32 DataSize = pFileHandle->Size();
	uint8 *pData = new uint8[DataSize];
	bool bReadResult = pFileHandle->Read(pData, DataSize);
	check(bReadResult);
	pFileHandle->Flush();
	delete pFileHandle;

	ExecuteScript((const char *) pData);
	delete[] pData;
}

// メッセージを表示.
void ScriptExecuter::ShowMessage_Impl(const std::string &Message)
{
	FString Msg = Message.c_str();
	pGameMode->ShowScriptMessage(Msg);
}

// 選択肢をプッシュ.
void ScriptExecuter::PushSelection_Impl(const std::string &Message)
{
}

// 選択肢を表示.
void ScriptExecuter::ShowSelection_Impl()
{
	UE_LOG(LogTemp, Log, TEXT("Show Selection"));
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
	UE_LOG(LogTemp, Log, TEXT("ScriptError:%s"), ANSI_TO_TCHAR(ErrorMessage.c_str()));

	// とりあえず終了する。
	pGameMode->FinishScript();
}

// 終了した。
void ScriptExecuter::OnFinished()
{
	pGameMode->FinishScript();
}

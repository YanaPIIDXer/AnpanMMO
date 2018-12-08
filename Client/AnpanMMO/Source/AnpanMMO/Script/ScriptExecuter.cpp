// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ScriptExecuter.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"
#include "Active/ActiveGameMode.h"

// �R���X�g���N�^
ScriptExecuter::ScriptExecuter()
{
}

// �X�N���v�g�����s.
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

// ���b�Z�[�W��\��.
void ScriptExecuter::ShowMessage_Impl(const std::string &Message)
{
	FString Msg = Message.c_str();
	pGameMode->ShowScriptMessage(Msg);
}

// �I�������v�b�V��.
void ScriptExecuter::PushSelection_Impl(const std::string &Message)
{
}

// �I������\��.
void ScriptExecuter::ShowSelection_Impl()
{
	UE_LOG(LogTemp, Log, TEXT("Show Selection"));
	// �������͖ⓚ���p�ŃC���f�b�N�X�O��I���B
	OnSelectedSelection(0);
}

// �t���O���Z�b�g
void ScriptExecuter::SetFlag(const char *pFlagName)
{
}

// �t���O���擾.
bool ScriptExecuter::GetFlag(const char *pFlagName)
{
	return false;
}

// ���s�G���[
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	UE_LOG(LogTemp, Log, TEXT("ScriptError:%s"), ANSI_TO_TCHAR(ErrorMessage.c_str()));

	// �Ƃ肠�����I������B
	pGameMode->FinishScript();
}

// �I�������B
void ScriptExecuter::OnFinished()
{
	pGameMode->FinishScript();
}

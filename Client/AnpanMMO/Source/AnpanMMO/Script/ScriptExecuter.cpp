// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ScriptExecuter.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"


// �R���X�g���N�^
ScriptExecuter::ScriptExecuter()
{
}

// �X�N���v�g�����s.
void ScriptExecuter::RunScript(const FString &FileName)
{
	FString Path = Config::GetScriptDirectory() + "\\" + FileName;

	IPlatformFile &File = FPlatformFileManager::Get().GetPlatformFile();
	IFileHandle *pFileHandle = File.OpenRead(*Path);
	int32 DataSize = pFileHandle->Size();
	uint8 *pData = new uint8[DataSize];
	bool bReadResult = pFileHandle->Read(pData, DataSize);
	check(bReadResult);
	pFileHandle->Flush();
	delete pFileHandle;

	ExecuteScript((const char *) pData);
}

// ���b�Z�[�W��\��.
void ScriptExecuter::ShowMessage_Impl(const std::string &Message)
{
	UE_LOG(LogTemp, Log, TEXT("Message:%s"), Message.c_str());
}

// �I�������v�b�V��.
void ScriptExecuter::PushSelection_Impl(const std::string &Message)
{
}

// �I������\��.
void ScriptExecuter::ShowSelection_Impl()
{
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
	UE_LOG(LogTemp, Log, TEXT("ScriptError:%s"), ErrorMessage.c_str());
}

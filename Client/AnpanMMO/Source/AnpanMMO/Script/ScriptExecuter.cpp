// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ScriptExecuter.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"
#include "Active/ActiveGameMode.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryStream/MemoryStreamReader.h"

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
		OnExecuteError(TCHAR_TO_UTF8(*ErrorMsg));
		return;
	}
	int32 DataSize = pFileHandle->Size();
	uint8 *pData = new uint8[DataSize];
	bool bReadResult = pFileHandle->Read(pData, DataSize);
	check(bReadResult);
	pFileHandle->Flush();
	delete pFileHandle;

	char *pCode = Composite(pData, DataSize);
	delete[] pData;

	ExecuteScript(pCode);
	delete[] pCode;
}

// ���b�Z�[�W��\��.
void ScriptExecuter::ShowMessage_Impl(const std::string &Message)
{
	FString Msg = UTF8_TO_TCHAR(Message.c_str());
	pGameMode->ShowScriptMessage(Msg);
}

// �I�������v�b�V��.
void ScriptExecuter::PushSelection_Impl(const std::string &Message)
{
	pGameMode->AddScriptSelection(UTF8_TO_TCHAR(Message.c_str()));
}

// �I������\��.
void ScriptExecuter::ShowSelection_Impl()
{
	pGameMode->ShowScriptSelection();
}

// �t���O���Z�b�g
void ScriptExecuter::SetFlag(int Flag)
{
	if (!FlagMap.Contains(Flag))
	{
		FlagMap.Add(Flag);
	}
	FlagMap[Flag] = true;
}

// �t���O���擾.
bool ScriptExecuter::GetFlag(int Flag)
{
	if (!FlagMap.Contains(Flag)) { return false; }
	return FlagMap[Flag];
}

// �N�G�X�g���i�s�����H
bool ScriptExecuter::IsQuestActive(u32 QuestId)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(pGameMode.Get()));
	check(pInst != nullptr);

	return pInst->GetQuestManager().IsActive(QuestId);
}

// �N�G�X�g�̃X�e�[�W�ԍ����擾.
u32 ScriptExecuter::GetQuestStageNo(u32 QuestId)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(pGameMode.Get()));
	check(pInst != nullptr);

	return pInst->GetQuestManager().GetStageNo(QuestId);
}

// �r�b�g�t�B�[���h����t���O�ɕϊ�.
void ScriptExecuter::ConvertFlagFromBitFields(uint32 BitField1, uint32 BitField2, uint32 BitField3)
{
	// �P��.
	for (int i = 0; i < 32; i++)
	{
		if (BitField1 & (1 << i))
		{
			SetFlag(i);
		}
	}

	// �Q��.
	for (int i = 0; i < 32; i++)
	{
		if (BitField2 & (1 << i))
		{
			SetFlag(i - 32);
		}
	}

	// �R��.
	for (int i = 0; i < 32; i++)
	{
		if (BitField3 & (1 << i))
		{
			SetFlag(i - 64);
		}
	}
}


// ���s�G���[
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	UE_LOG(LogTemp, Log, TEXT("ScriptError:%s"), UTF8_TO_TCHAR(ErrorMessage.c_str()));

	// �Ƃ肠�����I������B
	pGameMode->FinishScript();
}

// �I�������B
void ScriptExecuter::OnFinished()
{
	pGameMode->FinishScript();
}

// �f�o�b�O�p���b�Z�[�W��\��.
void ScriptExecuter::ShowDebugMessage(const std::string &Message)
{
	UE_LOG(LogTemp, Log, TEXT("Script Debug Message:%s"), UTF8_TO_TCHAR(Message.c_str()));
}


// ������.
char *ScriptExecuter::Composite(const uint8 *pData, int32 DataSize)
{
	MemoryStreamReader Reader(pData, DataSize);
	char *Ch = new char[2048];
	memset(Ch, 0, 2048);
	int Index = 0;
	int32 BitCount = 0;
	while (true)
	{
		int32 Bit = 0;
		int32 Count = 0;
		if (!Reader.Serialize(&Bit)) { break; }
		if (!Reader.Serialize(&Count)) { break; }
		for (int i = 0; i < Count; i++)
		{
			Ch[Index] |= (Bit << BitCount);
			BitCount++;
			if (BitCount >= 8)
			{
				Index++;
				BitCount = 0;
			}
		}
	}

	return Ch;
}

// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "ScriptExecuter.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"
#include "Active/ActiveGameMode.h"
#include "MMOGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "MemoryStream/MemoryStreamReader.h"

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

// メッセージを表示.
void ScriptExecuter::ShowMessage_Impl(const std::string &Message)
{
	FString Msg = UTF8_TO_TCHAR(Message.c_str());
	pGameMode->ShowScriptMessage(Msg);
}

// 選択肢をプッシュ.
void ScriptExecuter::PushSelection_Impl(const std::string &Message)
{
	pGameMode->AddScriptSelection(UTF8_TO_TCHAR(Message.c_str()));
}

// 選択肢を表示.
void ScriptExecuter::ShowSelection_Impl()
{
	pGameMode->ShowScriptSelection();
}

// フラグをセット
void ScriptExecuter::SetFlag(int Flag)
{
	if (!FlagMap.Contains(Flag))
	{
		FlagMap.Add(Flag);
	}
	FlagMap[Flag] = true;
}

// フラグを取得.
bool ScriptExecuter::GetFlag(int Flag)
{
	if (!FlagMap.Contains(Flag)) { return false; }
	return FlagMap[Flag];
}

// クエストが進行中か？
bool ScriptExecuter::IsQuestActive(u32 QuestId)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(pGameMode.Get()));
	check(pInst != nullptr);

	return pInst->GetQuestManager().IsActive(QuestId);
}

// クエストのステージ番号を取得.
u32 ScriptExecuter::GetQuestStageNo(u32 QuestId)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(pGameMode.Get()));
	check(pInst != nullptr);

	return pInst->GetQuestManager().GetStageNo(QuestId);
}

// ビットフィールドからフラグに変換.
void ScriptExecuter::ConvertFlagFromBitFields(uint32 BitField1, uint32 BitField2, uint32 BitField3)
{
	// １つ目.
	for (int i = 0; i < 32; i++)
	{
		if (BitField1 & (1 << i))
		{
			SetFlag(i);
		}
	}

	// ２つ目.
	for (int i = 0; i < 32; i++)
	{
		if (BitField2 & (1 << i))
		{
			SetFlag(i - 32);
		}
	}

	// ３つ目.
	for (int i = 0; i < 32; i++)
	{
		if (BitField3 & (1 << i))
		{
			SetFlag(i - 64);
		}
	}
}


// 実行エラー
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	UE_LOG(LogTemp, Log, TEXT("ScriptError:%s"), UTF8_TO_TCHAR(ErrorMessage.c_str()));

	// とりあえず終了する。
	pGameMode->FinishScript();
}

// 終了した。
void ScriptExecuter::OnFinished()
{
	pGameMode->FinishScript();
}

// デバッグ用メッセージを表示.
void ScriptExecuter::ShowDebugMessage(const std::string &Message)
{
	UE_LOG(LogTemp, Log, TEXT("Script Debug Message:%s"), UTF8_TO_TCHAR(Message.c_str()));
}


// 複合化.
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

#include "stdafx.h"
#include "ScriptExecuter.h"
#include "Client.h"
#include <fstream>
#include "CacheServer/CacheServerConnection.h"
#include "Character/Player/PlayerCharacter.h"
#include "Packet/CachePacketScriptFlagSaveRequest.h"

// コンストラクタ
ScriptExecuter::ScriptExecuter()
{
}

// 読み込んで実行.
void ScriptExecuter::LoadAndRun(const std::string &FileName)
{
	std::string FilePath = "../../Script/Scripts/" + FileName + ".lua";
	std::ifstream FileStream(FilePath.c_str());
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
		Code += "\n";
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

// クエストが進行中か？
bool ScriptExecuter::IsQuestActive(u32 QuestId)
{
	return pClient->GetQuestManager().IsActive(QuestId);
}

// クエスト進行.
void ScriptExecuter::ProgressQuest(u32 QuestId)
{
	pClient->ProgressQuest(QuestId);
}

// クエストのステージ番号を取得.
u32 ScriptExecuter::GetQuestStageNo(u32 QuestId)
{
	return pClient->GetQuestManager().GetStageNo(QuestId);
}

// アイテムの個数を取得.
u32 ScriptExecuter::GetItemCount(u32 ItemId)
{
	return pClient->GetCharacter().lock()->GetItemList().GetCount(ItemId);
}

// アイテム消費.
void ScriptExecuter::ConsumeItem(u32 ItemId, u32 Count)
{
	pClient->GetCharacter().lock()->SubtractItem(ItemId, Count);
}


// 実行エラー
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	std::cout << "Script Error:" << ErrorMessage << std::endl;
}

// 終了した。
void ScriptExecuter::OnFinished()
{
	u32 BitField1, BitField2, BitField3;
	pClient->GetScriptFlagManager().ToBitField(BitField1, BitField2, BitField3);

	CachePacketScriptFlagSaveRequest Packet(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId(), BitField1, BitField2, BitField3);
	CacheServerConnection::GetInstance()->SendPacket(&Packet);
}

// デバッグメッセージを表示.
void ScriptExecuter::ShowDebugMessage(const std::string &Message)
{
	std::cout << "Script Debug:" << Message << std::endl;
}

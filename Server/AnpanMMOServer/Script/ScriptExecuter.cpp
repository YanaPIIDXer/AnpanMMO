#include "stdafx.h"
#include "ScriptExecuter.h"
#include "Client.h"
#include <fstream>
#include "CacheServer/CacheServerConnection.h"
#include "Character/Player/PlayerCharacter.h"
#include "Packet/CachePacketScriptFlagSaveRequest.h"

// �R���X�g���N�^
ScriptExecuter::ScriptExecuter()
{
}

// �ǂݍ���Ŏ��s.
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

	// BOM�𖳎�����B
	Code = Code.substr(3);
	ExecuteScript(Code.c_str());
}

// �t���O���Z�b�g�B
void ScriptExecuter::SetFlag(int Flag)
{
	pClient->SetScriptFlag(Flag);
}

// �t���O���擾.
bool ScriptExecuter::GetFlag(int Flag)
{
	return pClient->GetScriptFlagManager().Get(Flag);
}

// �N�G�X�g���i�s�����H
bool ScriptExecuter::IsQuestActive(u32 QuestId)
{
	return pClient->GetQuestManager().IsActive(QuestId);
}

// �N�G�X�g�i�s.
void ScriptExecuter::ProgressQuest(u32 QuestId)
{
	pClient->ProgressQuest(QuestId);
}

// �N�G�X�g�̃X�e�[�W�ԍ����擾.
u32 ScriptExecuter::GetQuestStageNo(u32 QuestId)
{
	return pClient->GetQuestManager().GetStageNo(QuestId);
}

// �A�C�e���̌����擾.
u32 ScriptExecuter::GetItemCount(u32 ItemId)
{
	return pClient->GetCharacter().lock()->GetItemList().GetCount(ItemId);
}

// �A�C�e������.
void ScriptExecuter::ConsumeItem(u32 ItemId, u32 Count)
{
	pClient->GetCharacter().lock()->SubtractItem(ItemId, Count);
}


// ���s�G���[
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	std::cout << "Script Error:" << ErrorMessage << std::endl;
}

// �I�������B
void ScriptExecuter::OnFinished()
{
	u32 BitField1, BitField2, BitField3;
	pClient->GetScriptFlagManager().ToBitField(BitField1, BitField2, BitField3);

	CachePacketScriptFlagSaveRequest Packet(pClient->GetUuid(), pClient->GetCharacter().lock()->GetCharacterId(), BitField1, BitField2, BitField3);
	CacheServerConnection::GetInstance()->SendPacket(&Packet);
}

// �f�o�b�O���b�Z�[�W��\��.
void ScriptExecuter::ShowDebugMessage(const std::string &Message)
{
	std::cout << "Script Debug:" << Message << std::endl;
}

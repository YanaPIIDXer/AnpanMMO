#include "stdafx.h"
#include "ScriptExecuter.h"
#include "Client.h"
#include <fstream>

// �R���X�g���N�^
ScriptExecuter::ScriptExecuter()
{
}

// �ǂݍ���Ŏ��s.
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


// ���s�G���[
void ScriptExecuter::OnExecuteError(const std::string &ErrorMessage)
{
	std::cout << "Script Error:" << ErrorMessage << std::endl;
}

// �f�o�b�O���b�Z�[�W��\��.
void ScriptExecuter::ShowDebugMessage(const std::string &Message)
{
	std::cout << "Script Debug:" << Message << std::endl;
}

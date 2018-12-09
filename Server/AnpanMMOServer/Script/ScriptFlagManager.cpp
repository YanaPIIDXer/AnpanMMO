#include "stdafx.h"
#include "ScriptFlagManager.h"

// �R���X�g���N�^
ScriptFlagManager::ScriptFlagManager()
{
}

// �Z�b�g
void ScriptFlagManager::Set(int Key)
{
	Flags[Key] = true;
}

// �擾.
bool ScriptFlagManager::Get(int Key) const
{
	FlagMap::const_iterator It = Flags.find(Key);
	if (It == Flags.end()) { return false; }
	return It->second;
}

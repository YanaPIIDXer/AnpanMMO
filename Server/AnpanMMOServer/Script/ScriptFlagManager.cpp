#include "stdafx.h"
#include "ScriptFlagManager.h"

// コンストラクタ
ScriptFlagManager::ScriptFlagManager()
{
}

// セット
void ScriptFlagManager::Set(int Key)
{
	Flags[Key] = true;
}

// 取得.
bool ScriptFlagManager::Get(int Key) const
{
	FlagMap::const_iterator It = Flags.find(Key);
	if (It == Flags.end()) { return false; }
	return It->second;
}

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

// ビットフィールドに変換.
void ScriptFlagManager::ToBitField(u32 &OutBitField1, u32 &OutBitField2, u32 &OutBitField3) const
{
	// １つ目.
	OutBitField1 = 0;
	for (int i = 0; i < 32; i++)
	{
		bool bFlag = Get(i);
		if (bFlag)
		{
			OutBitField1 |= (1 << i);
		}
	}

	// ２つ目.
	OutBitField2 = 0;
	for (int i = 32; i < 64; i++)
	{
		bool bFlag = Get(i);
		if (bFlag)
		{
			OutBitField2 |= (1 << (i - 32));
		}
	}

	// ３つ目.
	OutBitField3 = 0;
	for (int i = 64; i < 96; i++)
	{
		bool bFlag = Get(i);
		if (bFlag)
		{
			OutBitField2 |= (1 << (i - 64));
		}
	}
}

// ビットフィールドから変換.
void ScriptFlagManager::FromBitField(u32 BitField1, u32 BitField2, u32 BitField3)
{
	// １つ目.
	for (int i = 0; i < 32; i++)
	{
		if (BitField1 & (1 << i))
		{
			Set(i);
		}
	}

	// ２つ目.
	for (int i = 0; i < 32; i++)
	{
		if (BitField2 & (1 << i))
		{
			Set(i + 32);
		}
	}

	// ３つ目.
	for (int i = 0; i < 32; i++)
	{
		if (BitField3 & (1 << i))
		{
			Set(i + 64);
		}
	}
}

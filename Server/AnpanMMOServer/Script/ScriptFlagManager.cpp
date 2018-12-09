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

// �r�b�g�t�B�[���h�ɕϊ�.
void ScriptFlagManager::ToBitField(u32 &OutBitField1, u32 &OutBitField2, u32 &OutBitField3) const
{
	// �P��.
	OutBitField1 = 0;
	for (int i = 0; i < 32; i++)
	{
		bool bFlag = Get(i);
		if (bFlag)
		{
			OutBitField1 |= (1 << i);
		}
	}

	// �Q��.
	OutBitField2 = 0;
	for (int i = 32; i < 64; i++)
	{
		bool bFlag = Get(i);
		if (bFlag)
		{
			OutBitField2 |= (1 << (i - 32));
		}
	}

	// �R��.
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

// �r�b�g�t�B�[���h����ϊ�.
void ScriptFlagManager::FromBitField(u32 BitField1, u32 BitField2, u32 BitField3)
{
	// �P��.
	for (int i = 0; i < 32; i++)
	{
		if (BitField1 & (1 << i))
		{
			Set(i);
		}
	}

	// �Q��.
	for (int i = 0; i < 32; i++)
	{
		if (BitField2 & (1 << i))
		{
			Set(i + 32);
		}
	}

	// �R��.
	for (int i = 0; i < 32; i++)
	{
		if (BitField3 & (1 << i))
		{
			Set(i + 64);
		}
	}
}

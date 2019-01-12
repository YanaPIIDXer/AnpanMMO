// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "VersionFile.h"

// �R���X�g���N�^
VersionFile::VersionFile()
{
}

// �R���X�g���N�^
VersionFile::VersionFile(const TArray<uint8> &Content)
{
	Configure(Content);
}

// �S�t�@�C�����擾.
TArray<FString> VersionFile::GetAllFiles() const
{
	TArray<FString> Files;
	for (auto KeyValue : HashMap)
	{
		Files.Add(KeyValue.Key);
	}
	return Files;
}

// �n�b�V���l���擾.
FString VersionFile::GetHash(const FString &FileName) const
{
	if (!HashMap.Contains(FileName)) { return ""; }
	return HashMap[FileName];
}

// �\�z.
void VersionFile::Configure(const TArray<uint8> &Content)
{
	HashMap.Reset();

	FString FileName = "";
	FString Hash = "";
	bool bHash = false;
	for (uint8 Ch : Content)
	{
		if (Ch == ',')
		{
			bHash = true;
			continue;
		}
		if (Ch == '\n')
		{
			bHash = false;
			HashMap.Add(FileName, Hash);
			FileName = "";
			Hash = "";
			continue;
		}
		if (!bHash)
		{
			FileName.AppendChar(Ch);
		}
		else
		{
			Hash.AppendChar(Ch);
		}
	}
}

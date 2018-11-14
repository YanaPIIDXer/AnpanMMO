// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * �o�[�W�����t�@�C���N���X
 */
class ANPANMMO_API VersionFile
{

public:

	// �R���X�g���N�^
	VersionFile();
	VersionFile(const TArray<uint8> &Content);

	// �f�X�g���N�^
	~VersionFile() {}

	// �S�t�@�C�����擾.
	TArray<FString> GetAllFiles() const;

	// �n�b�V���l���擾.
	FString GetHash(const FString &FileName) const;

	// �\�z.
	void Configure(const TArray<uint8> &Content);

private:

	// �n�b�V���l�̃}�b�v
	TMap<FString, FString> HashMap;

};

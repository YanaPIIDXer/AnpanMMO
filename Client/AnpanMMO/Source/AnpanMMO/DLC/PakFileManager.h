// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PakFile/Public/IPlatformFilePak.h"

/**
 * Pak�t�@�C���Ǘ�.
 */
class ANPANMMO_API PakFileManager : public FNoncopyable
{

public:

	// �f�X�g���N�^
	~PakFileManager();

	// ������.
	void Initialize();

	// �}�E���g
	void Mount(const FString &Path);

private:

	// PakPlatformFile
	FPakPlatformFile *pPakPlatform;

	// �}�E���g�ς݂̃p�X.
	TArray<FString> MountedPaths;

	// =========== Singleton =================
public:

	static PakFileManager &GetInstance() { return Instance; }

private:

	PakFileManager();
	static PakFileManager Instance;


};

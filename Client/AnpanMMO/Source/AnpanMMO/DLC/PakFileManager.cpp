// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PakFileManager.h"
#include "HAL/PlatformFilemanager.h"

PakFileManager PakFileManager::Instance;

// �R���X�g���N�^
PakFileManager::PakFileManager()
	: pPakPlatform(nullptr)
{
}

// �f�X�g���N�^
PakFileManager::~PakFileManager()
{
#if !WITH_EDITOR
	delete pPakPlatform;
	pPakPlatform = nullptr;
#endif
}

// ������.
void PakFileManager::Initialize()
{
#if !WITH_EDITOR
	if (pPakPlatform != nullptr) { return; }

	IPlatformFile &InnerPlatform = FPlatformFileManager::Get().GetPlatformFile();
	pPakPlatform = new FPakPlatformFile();
	pPakPlatform->Initialize(&InnerPlatform, TEXT(""));
	FPlatformFileManager::Get().SetPlatformFile(*pPakPlatform);
#endif
}

// �}�E���g
bool PakFileManager::Mount(const FString &Path)
{
#if !WITH_EDITOR
	// �}�E���g�ς݁B
	if (MountedPaths.Find(Path)) { return true; }
	if (!pPakPlatform->Mount(*Path, 0, *FPaths::GameContentDir()))
	{
		UE_LOG(LogTemp, Log, TEXT("%s Mount Failed..."), *Path);
		return false;
	}
	MountedPaths.Add(Path);
#endif
	return true;
}

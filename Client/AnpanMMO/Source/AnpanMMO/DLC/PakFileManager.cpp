// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PakFileManager.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/CoreDelegates.h"

PakFileManager PakFileManager::Instance;

// コンストラクタ
PakFileManager::PakFileManager()
	: pPakPlatform(nullptr)
{
}

// デストラクタ
PakFileManager::~PakFileManager()
{
#if !WITH_EDITOR
	delete pPakPlatform;
	pPakPlatform = nullptr;
#endif
}

// 初期化.
void PakFileManager::Initialize()
{
#if !WITH_EDITOR
	if (pPakPlatform != nullptr) { return; }

	IPlatformFile &InnerPlatform = FPlatformFileManager::Get().GetPlatformFile();
	pPakPlatform = new FPakPlatformFile();
	pPakPlatform->Initialize(&InnerPlatform, TEXT(""));
	pPakPlatform->InitializeNewAsyncIO();
	FPlatformFileManager::Get().SetPlatformFile(*pPakPlatform);
#endif
}

// マウント
bool PakFileManager::Mount(const FString &Path)
{
#if !WITH_EDITOR
	// マウント済み。
	// if(MountedPaths.Find(Path)) { return true; }		// ←何故か問答無用でtrueが返される。
	int DummyIndex = 0;
	if (MountedPaths.Find(Path, DummyIndex)) { return true; }

	FString MountPoint = FPaths::ProjectDir();
	FPaths::MakeStandardFilename(MountPoint);
	MountPoint = FPaths::GetPath(MountPoint);
	if (!pPakPlatform->Mount(*Path, 4, *MountPoint))
	{
		UE_LOG(LogTemp, Log, TEXT("%s Mount Failed..."), *Path);
		return false;
	}
	MountedPaths.Add(Path);
#endif
	return true;
}

// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PakFile/Public/IPlatformFilePak.h"

/**
 * Pakファイル管理.
 */
class ANPANMMO_API PakFileManager : public FNoncopyable
{

public:

	// デストラクタ
	~PakFileManager();

	// 初期化.
	void Initialize();

	// マウント
	void Mount(const FString &Path);

private:

	// PakPlatformFile
	FPakPlatformFile *pPakPlatform;

	// マウント済みのパス.
	TArray<FString> MountedPaths;

	// =========== Singleton =================
public:

	static PakFileManager &GetInstance() { return Instance; }

private:

	PakFileManager();
	static PakFileManager Instance;


};

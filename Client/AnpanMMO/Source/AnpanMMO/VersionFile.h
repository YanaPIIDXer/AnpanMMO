// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * バージョンファイルクラス
 */
class ANPANMMO_API VersionFile
{

public:

	// コンストラクタ
	VersionFile();
	VersionFile(const TArray<uint8> &Content);

	// デストラクタ
	~VersionFile() {}

	// 全ファイルを取得.
	TArray<FString> GetAllFiles() const;

	// ハッシュ値を取得.
	FString GetHash(const FString &FileName) const;

	// 構築.
	void Configure(const TArray<uint8> &Content);

private:

	// ハッシュ値のマップ
	TMap<FString, FString> HashMap;

};

// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Connection/HttpConnection.h"

DECLARE_DELEGATE_OneParam(FDownloadResult, bool);

/**
 * バージョンファイルで管理されたファイルのダウンロードクラス
 */
class ANPANMMO_API VersionDownloader
{

public:

	// コンストラクタ
	VersionDownloader();

	// デストラクタ
	~VersionDownloader() {}

	// 開始.
	bool Start(const FString &InURL, const FString &InSavePath);

	// ダウンロード結果delegate
	FDownloadResult DownloadResult;
	
private:

	// HTTP通信.
	HttpConnection Http;

	// ダウンロードしてきたバージョンファイルデータ
	TArray<uint8> DownloadedVersionFileData;

	// ダウンロードキュー
	TArray<FString> DownloadQueue;

	// URL
	FString URL;

	// 保存先パス
	FString SavePath;


	// バージョンファイルのダウンロードが完了した。
	void OnDownloadVersionFile(bool bSuccess, const TArray<uint8> &Content);

	// ファイルのダウンロードが完了した。
	void OnDownloadFile(bool bSuccess, const TArray<uint8> &Content);

	// ダウンロードしてきたバージョンファイルを保存.
	void SaveDownloadedVersionFile();

};

// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Connection/HttpConnection.h"

DECLARE_DELEGATE_OneParam(FMasterDownloadResult, bool);

/**
 * マスタダウンロードクラス
 */
class ANPANMMO_API MasterDownloader
{

public:

	// コンストラクタ
	MasterDownloader();

	// デストラクタ
	~MasterDownloader() {}

	// 開始.
	bool Start();

	// ダウンロード結果delegate
	FMasterDownloadResult DownloadResult;
	
private:

	// HTTP通信.
	HttpConnection Http;

	// ダウンロードしてきたバージョンファイルデータ
	TArray<uint8> DownloadedVersionFileData;

	// ダウンロードキュー
	TArray<FString> DownloadQueue;


	// バージョンファイルのダウンロードが完了した。
	void OnDownloadVersionFile(bool bSuccess, const TArray<uint8> &Content);

	// マスタファイルのダウンロードが完了した。
	void OnDownloadMasterFile(bool bSuccess, const TArray<uint8> &Content);

	// ダウンロードしてきたバージョンファイルを保存.
	void SaveDownloadedVersionFile();

};

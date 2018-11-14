// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/HTTP/Public/Http.h"

DECLARE_DELEGATE_TwoParams(FDownloadFinished, bool, const TArray<uint8> &);

/**
 * HTTP通信クラス
 */
class ANPANMMO_API HttpConnection
{

public:

	// コンストラクタ
	HttpConnection();

	// デストラクタ
	~HttpConnection();

	// ダウンロード開始.
	bool StartDownload(const FString &URL);

	// 閉じる。
	void Close();

	// ダウンロード完了時delegate
	FDownloadFinished DownloadFinished;

private:

	// HTTP通信モジュール
	FHttpModule *pHttp;


	// レスポンスを受信した。
	void OnResponseReceived(FHttpRequestPtr pRequest, FHttpResponsePtr pResponse, bool bSuccess);

};

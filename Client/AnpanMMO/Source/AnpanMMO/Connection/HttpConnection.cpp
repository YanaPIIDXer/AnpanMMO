// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "HttpConnection.h"

// コンストラクタ
HttpConnection::HttpConnection()
	: pHttp(nullptr)
{
}

// デストラクタ
HttpConnection::~HttpConnection()
{
	Close();
}

// ダウンロード開始.
bool HttpConnection::StartDownload(const FString &URL)
{
	if (pHttp != nullptr)
	{
		Close();
	}

	pHttp = &FHttpModule::Get();
	if (pHttp == nullptr) { return false; }

	TSharedRef<IHttpRequest> Request = pHttp->CreateRequest();
	Request->OnProcessRequestComplete().BindRaw<HttpConnection>(this, &HttpConnection::OnResponseReceived);
	Request->SetURL(URL);
	Request->SetVerb("GET");
	Request->SetHeader(TEXT("User-Agent"), "AnpanMMO");
	if (!Request->ProcessRequest()) { return false; }

	return true;
}

// 閉じる。
void HttpConnection::Close()
{
	pHttp = nullptr;
}


// レスポンスを受信した。
void HttpConnection::OnResponseReceived(FHttpRequestPtr pRequest, FHttpResponsePtr pResponse, bool bSuccess)
{
	TArray<uint8> Content;
	if (!pResponse.IsValid())
	{
		DownloadFinished.ExecuteIfBound(false, Content);
		Close();
		return;
	}
	if (pResponse->GetResponseCode() != 200)
	{
		DownloadFinished.ExecuteIfBound(false, Content);
		Close();
		return;
	}

	if (!bSuccess)
	{
		DownloadFinished.ExecuteIfBound(false, Content);
		Close();
		return;
	}
	Content = pResponse->GetContent();
	DownloadFinished.ExecuteIfBound(true, Content);

	Close();
}

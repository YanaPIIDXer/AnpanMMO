// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "HttpConnection.h"

// �R���X�g���N�^
HttpConnection::HttpConnection()
	: pHttp(nullptr)
{
}

// �f�X�g���N�^
HttpConnection::~HttpConnection()
{
	Close();
}

// �_�E�����[�h�J�n.
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

// ����B
void HttpConnection::Close()
{
	pHttp = nullptr;
}


// ���X�|���X����M�����B
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

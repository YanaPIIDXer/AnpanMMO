// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/HTTP/Public/Http.h"

DECLARE_DELEGATE_TwoParams(FDownloadFinished, bool, const TArray<uint8> &);

/**
 * HTTP�ʐM�N���X
 */
class ANPANMMO_API HttpConnection
{

public:

	// �R���X�g���N�^
	HttpConnection();

	// �f�X�g���N�^
	~HttpConnection();

	// �_�E�����[�h�J�n.
	bool StartDownload(const FString &URL);

	// ����B
	void Close();

	// �_�E�����[�h������delegate
	FDownloadFinished DownloadFinished;

private:

	// HTTP�ʐM���W���[��
	FHttpModule *pHttp;


	// ���X�|���X����M�����B
	void OnResponseReceived(FHttpRequestPtr pRequest, FHttpResponsePtr pResponse, bool bSuccess);

};

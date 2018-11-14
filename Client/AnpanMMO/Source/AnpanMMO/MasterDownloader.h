// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Connection/HttpConnection.h"

DECLARE_DELEGATE_OneParam(FMasterDownloadResult, bool);

/**
 * �}�X�^�_�E�����[�h�N���X
 */
class ANPANMMO_API MasterDownloader
{

public:

	// �R���X�g���N�^
	MasterDownloader();

	// �f�X�g���N�^
	~MasterDownloader() {}

	// �J�n.
	bool Start();

	// �_�E�����[�h����delegate
	FMasterDownloadResult DownloadResult;
	
private:

	// HTTP�ʐM.
	HttpConnection Http;

	// �_�E�����[�h���Ă����o�[�W�����t�@�C���f�[�^
	TArray<uint8> DownloadedVersionFileData;

	// �_�E�����[�h�L���[
	TArray<FString> DownloadQueue;


	// �o�[�W�����t�@�C���̃_�E�����[�h�����������B
	void OnDownloadVersionFile(bool bSuccess, const TArray<uint8> &Content);

	// �}�X�^�t�@�C���̃_�E�����[�h�����������B
	void OnDownloadMasterFile(bool bSuccess, const TArray<uint8> &Content);

	// �_�E�����[�h���Ă����o�[�W�����t�@�C����ۑ�.
	void SaveDownloadedVersionFile();

};

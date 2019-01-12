// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Connection/HttpConnection.h"

DECLARE_DELEGATE_OneParam(FDownloadResult, bool);

/**
 * �o�[�W�����t�@�C���ŊǗ����ꂽ�t�@�C���̃_�E�����[�h�N���X
 */
class ANPANMMO_API VersionDownloader
{

public:

	// �R���X�g���N�^
	VersionDownloader();

	// �f�X�g���N�^
	~VersionDownloader() {}

	// �J�n.
	bool Start(const FString &InURL, const FString &InSavePath);

	// �_�E�����[�h����delegate
	FDownloadResult DownloadResult;
	
private:

	// HTTP�ʐM.
	HttpConnection Http;

	// �_�E�����[�h���Ă����o�[�W�����t�@�C���f�[�^
	TArray<uint8> DownloadedVersionFileData;

	// �_�E�����[�h�L���[
	TArray<FString> DownloadQueue;

	// URL
	FString URL;

	// �ۑ���p�X
	FString SavePath;


	// �o�[�W�����t�@�C���̃_�E�����[�h�����������B
	void OnDownloadVersionFile(bool bSuccess, const TArray<uint8> &Content);

	// �t�@�C���̃_�E�����[�h�����������B
	void OnDownloadFile(bool bSuccess, const TArray<uint8> &Content);

	// �_�E�����[�h���Ă����o�[�W�����t�@�C����ۑ�.
	void SaveDownloadedVersionFile();

};

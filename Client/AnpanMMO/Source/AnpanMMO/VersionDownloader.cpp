// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "VersionDownloader.h"
#include "Config.h"
#include "VersionFile.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

// �R���X�g���N�^
VersionDownloader::VersionDownloader()
	: URL("")
	, SavePath("")
{
}

// �J�n.
bool VersionDownloader::Start(const FString &InURL, const FString &InSavePath)
{
	URL = InURL;
	SavePath = InSavePath;

	Http.DownloadFinished.BindRaw<VersionDownloader>(this, &VersionDownloader::OnDownloadVersionFile);

	FString VersionFileURL = URL + "Version.csv";
	if (!Http.StartDownload(VersionFileURL)) { return false; }
	return true;
}


// �o�[�W�����t�@�C���̃_�E�����[�h�����������B
void VersionDownloader::OnDownloadVersionFile(bool bSuccess, const TArray<uint8> &Content)
{
	if (!bSuccess)
	{
		DownloadResult.ExecuteIfBound(false);
		return;
	}

	DownloadedVersionFileData = Content;

	IPlatformFile &File = FPlatformFileManager::Get().GetPlatformFile();

	if (!File.DirectoryExists(*SavePath))
	{
		File.CreateDirectory(*SavePath);
	}

	VersionFile DownloadedVersionFile(Content);

	Http.DownloadFinished.BindRaw<VersionDownloader>(this, &VersionDownloader::OnDownloadFile);
	
	FString VersionFilePath = SavePath + "\\Version.csv";
	if (!File.FileExists(*VersionFilePath))
	{
		// �o�[�W�����t�@�C�����Ȃ��B
		DownloadQueue = DownloadedVersionFile.GetAllFiles();
		if (DownloadQueue.Num() == 0)
		{
			SaveDownloadedVersionFile();
			DownloadResult.ExecuteIfBound(true);
			return;
		}
		Http.StartDownload(URL + DownloadQueue[0]);
		return;
	}

	IFileHandle *pFileHandle = File.OpenRead(*VersionFilePath);
	uint8 Data[2048];
	pFileHandle->Read(Data, 2048);
	pFileHandle->Flush();
	delete pFileHandle;
	
	TArray<uint8> LocalData;
	for (uint8 Ch : Data)
	{
		LocalData.Add(Ch);
	}
	VersionFile LocalVersionFile(LocalData);
	TArray<FString> FileList = DownloadedVersionFile.GetAllFiles();
	for (FString FileName : FileList)
	{
		if (!File.FileExists(*(SavePath + "\\" + FileName)))
		{
			// ���[�J���ɂ͑��݂��Ȃ��t�@�C��
			DownloadQueue.Add(FileName);
			continue;
		}

		FString LocalHash = LocalVersionFile.GetHash(FileName);
		if (LocalHash == "")
		{
			// ���[�J���ɂ͑��݂��Ȃ��n�Y�̃t�@�C��
			DownloadQueue.Add(FileName);
			continue;
		}
		FString DownloadedHash = DownloadedVersionFile.GetHash(FileName);
		if (LocalHash != DownloadedHash)
		{
			// �f�[�^�̍X�V�������Ă���t�@�C���B
			DownloadQueue.Add(FileName);
		}
	}

	if (DownloadQueue.Num() == 0)
	{
		SaveDownloadedVersionFile();
		DownloadResult.ExecuteIfBound(true);
		return;
	}
	
	Http.StartDownload(URL + DownloadQueue[0]);
}

// �t�@�C���̃_�E�����[�h�����������B
void VersionDownloader::OnDownloadFile(bool bSuccess, const TArray<uint8> &Content)
{
	if (!bSuccess)
	{
		DownloadResult.ExecuteIfBound(false);
		return;
	}

	IPlatformFile &File = FPlatformFileManager::Get().GetPlatformFile();
	FString FilePath = SavePath + "\\" + DownloadQueue[0];
	IFileHandle *pFileHandle = File.OpenWrite(*FilePath);
	pFileHandle->Write(&Content[0], Content.Num());
	pFileHandle->Flush();
	delete pFileHandle;

	DownloadQueue.RemoveAt(0, 1);
	if (DownloadQueue.Num() == 0)
	{
		// �S���_�E�����[�h�����������B
		SaveDownloadedVersionFile();
		DownloadResult.ExecuteIfBound(true);
		return;
	}

	Http.StartDownload(URL + DownloadQueue[0]);
}

// �_�E�����[�h���Ă����o�[�W�����t�@�C����ۑ�.
void VersionDownloader::SaveDownloadedVersionFile()
{
	IPlatformFile &File = FPlatformFileManager::Get().GetPlatformFile();
	FString VersionFilePath = SavePath + "\\Version.csv";
	IFileHandle *pFileHandle = File.OpenWrite(*VersionFilePath);
	pFileHandle->Write(&DownloadedVersionFileData[0], DownloadedVersionFileData.Num());
	pFileHandle->Flush();
	delete pFileHandle;
}

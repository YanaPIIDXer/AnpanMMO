// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MasterDownloader.h"
#include "Config.h"
#include "VersionFile.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

// コンストラクタ
MasterDownloader::MasterDownloader()
{
}

// 開始.
bool MasterDownloader::Start()
{
	Http.DownloadFinished.BindRaw<MasterDownloader>(this, &MasterDownloader::OnDownloadVersionFile);

	FString VersionFileURL = Config::MasterURL + "Version.csv";
	if (!Http.StartDownload(VersionFileURL)) { return false; }
	return true;
}


// バージョンファイルのダウンロードが完了した。
void MasterDownloader::OnDownloadVersionFile(bool bSuccess, const TArray<uint8> &Content)
{
	if (!bSuccess)
	{
		DownloadResult.ExecuteIfBound(false);
		return;
	}

	DownloadedVersionFileData = Content;

	IPlatformFile &File = FPlatformFileManager::Get().GetPlatformFile();

	FString DirName = Config::GetMasterDirectory();
	if (!File.DirectoryExists(*DirName))
	{
		File.CreateDirectory(*DirName);
	}

	VersionFile DownloadedVersionFile(Content);

	Http.DownloadFinished.BindRaw<MasterDownloader>(this, &MasterDownloader::OnDownloadMasterFile);
	
	FString VersionFilePath = DirName + "\\Version.csv";
	if (!File.FileExists(*VersionFilePath))
	{
		// バージョンファイルがない。
		DownloadQueue = DownloadedVersionFile.GetAllFiles();
		if (DownloadQueue.Num() == 0)
		{
			SaveDownloadedVersionFile();
			DownloadResult.ExecuteIfBound(true);
			return;
		}
		Http.StartDownload(Config::MasterURL + DownloadQueue[0]);
		return;
	}

	FString VersionFileName = VersionFilePath + "\\Version.csv";
	IFileHandle *pFileHandle = File.OpenRead(*VersionFileName);
	uint8 Data[2048];
	pFileHandle->Read(Data, 2048);
	TArray<uint8> LocalData;
	for (uint8 Ch : Data)
	{
		LocalData.Add(Ch);
	}
	VersionFile LocalVersionFile(LocalData);
	TArray<FString> FileList = DownloadedVersionFile.GetAllFiles();
	for (FString FileName : FileList)
	{
		if (!File.FileExists(*(DirName + "\\" + FileName)))
		{
			// ローカルには存在しないファイル
			DownloadQueue.Add(FileName);
			continue;
		}

		FString LocalHash = LocalVersionFile.GetHash(FileName);
		if (LocalHash == "")
		{
			// ローカルには存在しないハズのファイル
			DownloadQueue.Add(FileName);
			continue;
		}
		FString DownloadedHash = DownloadedVersionFile.GetHash(FileName);
		if (LocalHash != DownloadedHash)
		{
			// データの更新が入っているファイル。
			DownloadQueue.Add(FileName);
		}
	}

	if (DownloadQueue.Num() == 0)
	{
		SaveDownloadedVersionFile();
		DownloadResult.ExecuteIfBound(true);
		return;
	}
	
	Http.StartDownload(Config::MasterURL + DownloadQueue[0]);
}

// マスタファイルのダウンロードが完了した。
void MasterDownloader::OnDownloadMasterFile(bool bSuccess, const TArray<uint8> &Content)
{
	if (!bSuccess)
	{
		DownloadResult.ExecuteIfBound(false);
		return;
	}

	IPlatformFile &File = FPlatformFileManager::Get().GetPlatformFile();
	FString FilePath = Config::GetMasterDirectory() + "\\" + DownloadQueue[0];
	IFileHandle *pFileHandle = File.OpenWrite(*FilePath);
	pFileHandle->Write(&Content[0], Content.Num());
	pFileHandle->Flush();

	DownloadQueue.RemoveAt(0, 1);
	if (DownloadQueue.Num() == 0)
	{
		// 全部ダウンロードが完了した。
		SaveDownloadedVersionFile();
		DownloadResult.ExecuteIfBound(true);
		return;
	}

	Http.StartDownload(Config::MasterURL + DownloadQueue[0]);
}

// ダウンロードしてきたバージョンファイルを保存.
void MasterDownloader::SaveDownloadedVersionFile()
{
	IPlatformFile &File = FPlatformFileManager::Get().GetPlatformFile();
	FString VersionFilePath = Config::GetMasterDirectory() + "\\Version.csv";
	IFileHandle *pFileHandle = File.OpenWrite(*VersionFilePath);
	pFileHandle->Write(&DownloadedVersionFileData[0], DownloadedVersionFileData.Num());
	pFileHandle->Flush();
}

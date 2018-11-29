// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "Config.h"
#include "Paths.h"

#if WITH_EDITOR
#define USE_LOCAL_SERVER
#endif

#ifndef USE_LOCAL_SERVER
const FString Config::ServerHost = "218.220.121.112";
#else
const FString Config::ServerHost = "127.0.0.1";
#endif

const int Config::ServerPort = 4424;

// ID�t�@�C���̃t�@�C���p�X�擾.
FString Config::GetIdFilePath()
{
	FString Path = "";
#if PLATFORM_WINDOWS
	// Windows����
	Path = FPaths::ProjectSavedDir();
#elif PLATFORM_ANDROID
	// Android����
	Path = "/storage/emulated/0/AnapnMMO";
#elif PLATFORM_IOS
	// iOS����
	Path = "";
#endif
	return Path;
}

#ifndef USE_LOCAL_SERVER
const FString Config::MasterURL = "http://218.220.121.112/~Master/anpanmmomaster/main/";
#else
const FString Config::MasterURL = "http://218.220.121.112/~Master/anpanmmomaster/local/";
#endif

// �}�X�^�f�B���N�g���擾.
FString Config::GetMasterDirectory()
{
	FString Path = "";
#if PLATFORM_WINDOWS
	// Windows����
	Path = FPaths::ProjectSavedDir() + "Master";
#elif PLATFORM_ANDROID
	// Android����
	Path = "/storage/emulated/0/AnapnMMO/Master";
#elif PLATFORM_IOS
	// iOS����
	Path = "";
#endif
	return Path;
}

const FString Config::DLCURL = "http://218.220.121.112/~Master/anpanmmo/dlc/";

// DLC�f�B���N�g�����擾.
FString Config::GetDLCDirectory()
{
	FString Path = "";
#if PLATFORM_WINDOWS
	Path = FPaths::ProjectSavedDir() + "DLC";
#elif PLATFORM_ANDROID
	// Android����
	Path = "/storage/emulated/0/AnapnMMO/DLC";
#elif PLATFORM_IOS
	// iOS����
	Path = "";
#endif
	return Path;
}

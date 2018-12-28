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

// IDファイルのファイルパス取得.
FString Config::GetIdFilePath()
{
	FString Path = "";
#if PLATFORM_WINDOWS
	// Windows向け
	Path = FPaths::ProjectSavedDir();
#elif PLATFORM_ANDROID
	// Android向け
	Path = "/storage/emulated/0/AnapnMMO";
#elif PLATFORM_IOS
	// iOS向け
	Path = "";
#endif
	return Path;
}

#ifndef USE_LOCAL_SERVER
const FString Config::MasterURL = "http://218.220.121.112/~Master/anpanmmomaster/main/";
#else
const FString Config::MasterURL = "http://218.220.121.112/~Master/anpanmmomaster/local/";
#endif

// マスタディレクトリ取得.
FString Config::GetMasterDirectory()
{
	FString Path = "";
#if PLATFORM_WINDOWS
	// Windows向け
	Path = FPaths::ProjectSavedDir() + "Master";
#elif PLATFORM_ANDROID
	// Android向け
	Path = "/storage/emulated/0/AnapnMMO/Master";
#elif PLATFORM_IOS
	// iOS向け
	Path = NSHomeDirectory() + "/Library/Application Support/AnpanMMO/Master";
#endif
	return Path;
}

const FString Config::ScriptURL = "http://218.220.121.112/~Master/anpanmmoscript/";

// スクリプトディレクトリを取得.
FString Config::GetScriptDirectory()
{
	FString Path = "";
#if PLATFORM_WINDOWS
	// Windows向け
	Path = FPaths::ProjectSavedDir() + "Script";
#elif PLATFORM_ANDROID
	// Android向け
	Path = "/storage/emulated/0/AnapnMMO/Script";
#elif PLATFORM_IOS
	// iOS向け
	Path = NSHomeDirectory() + "/Library/Application Support/AnpanMMO/Script";
#endif
	return Path;
}

const FString Config::DLCURL = "http://218.220.121.112/~Master/anpanmmo/dlc/";

// DLCのURLを取得
FString Config::GetDLCURL()
{
	FString URL = DLCURL;

#if PLATFORM_WINDOWS

	URL += "windows/";

#elif PLATFORM_ANDROID

	URL += "android/";

#elif PLATFORM_IOS

	URL += "ios/";

#endif

	return URL;
}

// DLCディレクトリを取得.
FString Config::GetDLCDirectory()
{
	FString Path = "";
#if PLATFORM_WINDOWS
	Path = FPaths::ProjectSavedDir() + "DLC";
#elif PLATFORM_ANDROID
	// Android向け
	Path = "/storage/emulated/0/AnapnMMO/DLC";
#elif PLATFORM_IOS
	// iOS向け
	Path = NSHomeDirectory() + "/Library/Application Support/AnpanMMO/DLC";
#endif
	return Path;
}

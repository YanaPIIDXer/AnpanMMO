// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "Config.h"
#include "Paths.h"

//#if WITH_EDITOR
#define USE_LOCAL_SERVER
//#endif

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


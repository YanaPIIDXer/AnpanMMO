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

#if PLATFORM_WINDOWS
// WindowsŒü‚¯
const FString Config::IdFilePath = FPaths::ProjectSavedDir();
#elif PLATFORM_ANDROID
// AndroidŒü‚¯
const FString Config::IdFilePath = "/storage/emulated/0/AnapnMMO";
#elif PLATFORM_IOS
// iOSŒü‚¯
const FString Config::IdFilePath = "";
#endif

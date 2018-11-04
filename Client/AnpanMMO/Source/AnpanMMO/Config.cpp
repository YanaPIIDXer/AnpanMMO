// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "Config.h"
#include "Paths.h"

#define USE_LOCAL_SERVER

#ifndef USE_LOCAL_SERVER
const FString Config::ServerHost = "218.220.121.112";
#else
const FString Config::ServerHost = "127.0.0.1";
#endif

const int Config::ServerPort = 4424;

#if PLATFORM_WINDOWS
// Windows向け
const FString Config::IdFilePath = FPaths::ProjectSavedDir();
#elif PLATFORM_ANDROID
// Android向け
const FString Config::IdFilePath = "";
#elif PLATFORM_IOS
// iOS向け
const FString Config::IdFilePath = "";
#endif

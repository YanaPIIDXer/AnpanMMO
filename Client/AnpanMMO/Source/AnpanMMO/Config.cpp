// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "Config.h"

#define USE_LOCAL_SERVER

#ifndef USE_LOCAL_SERVER

const FString Config::ServerHost = "218.220.121.112";

#else

const FString Config::ServerHost = "127.0.0.1";

#endif

const int Config::ServerPort = 4424;

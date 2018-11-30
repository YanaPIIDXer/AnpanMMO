#include "stdafx.h"
#include "ServerHost.h"

#if WIN32
//#define USE_REMOTE_CACHESERVER
//#define USE_REMOTE_WORDCHECKSERVER
#endif

#ifndef USE_REMOTE_CACHESERVER
const std::string ServerHost::CacheServerHost = "127.0.0.1";
#else
const std::string ServerHost::CacheServerHost = "218.220.121.112";
#endif

#ifndef USE_REMOTE_WORDCHECKSERVER
const std::string ServerHost::WordCheckServerHost = "127.0.0.1";
#else
const std::string ServerHost::WordCheckServerHost = "218.220.121.112";
#endif

const int ServerHost::GameServerPort = 4424;
const int ServerHost::CacheServerPort = 4425;
const int ServerHost::WordCheckServerPort = 4426;

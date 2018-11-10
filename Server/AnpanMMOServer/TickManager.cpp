#include "stdafx.h"
#include "TickManager.h"
#include <time.h>

TickManager TickManager::Instance;

// コンストラクタ
TickManager::TickManager()
{
	GetTime(&PrevTime);
}

// 毎フレームの処理.
void TickManager::Poll()
{
	timespec CurrentTime;
	GetTime(&CurrentTime);
	int DeltaTime = (CurrentTime.tv_nsec - PrevTime.tv_nsec) / 1000000;
	if (DeltaTime < 0)
	{
		// たまにCurrentTime < PrevTimeになるようなので対処。
		DeltaTime = 0;
	}
	
	for (int i = 0; i < Functions.size(); i++)
	{
		Functions[i](DeltaTime);
	}

	PrevTime = CurrentTime;
}

// 追加.
void TickManager::Add(const TickFunction &Function)
{
	Functions.push_back(Function);
}


// 時間を取得.
void TickManager::GetTime(timespec *pTime)
{
	// ※WindowsとLinuxで定義されている関数が分かれているので
	// 　こういった対処を行っている。
#if WIN32
	timespec_get(pTime, TIME_UTC);
#else
	clock_gettime(CLOCK_REALTIME, pTime);
#endif
}

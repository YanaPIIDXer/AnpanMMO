#include "stdafx.h"
#include "TickManager.h"
#include <time.h>
#if !WIN32
#include <sys/time.h>
#endif

TickManager TickManager::Instance;

// コンストラクタ
TickManager::TickManager()
{
	PrevTime = clock();
}

// 毎フレームの処理.
void TickManager::Poll()
{
	clock_t CurrentTime = clock();
	time_t DeltaTime = difftime(CurrentTime, PrevTime);

	std::cout << "TickManager::Poll() DeltaTime:" << DeltaTime << "(PrevTime:" << PrevTime << " CurrentTime:" << CurrentTime << ")" << std::endl;
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

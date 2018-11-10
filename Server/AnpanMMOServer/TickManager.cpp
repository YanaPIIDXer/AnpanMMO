#include "stdafx.h"
#include "TickManager.h"
#include <time.h>

TickManager TickManager::Instance;

// �R���X�g���N�^
TickManager::TickManager()
{
	GetTime(&PrevTime);
}

// ���t���[���̏���.
void TickManager::Poll()
{
	timespec CurrentTime;
	GetTime(&CurrentTime);
	int DeltaTime = (CurrentTime.tv_nsec - PrevTime.tv_nsec) / 1000000;

	std::cout << "TickManager::Poll() DeltaTime:" << DeltaTime << "(PrevTime:" << PrevTime.tv_nsec << " CurrentTime:" << CurrentTime.tv_nsec << ")" << std::endl;
	for (int i = 0; i < Functions.size(); i++)
	{
		Functions[i](DeltaTime);
	}

	PrevTime = CurrentTime;
}

// �ǉ�.
void TickManager::Add(const TickFunction &Function)
{
	Functions.push_back(Function);
}


// ���Ԃ��擾.
void TickManager::GetTime(timespec *pTime)
{
#if WIN32
	timespec_get(pTime, TIME_UTC);
#else
	clock_gettime(CLOCK_REALTIME, pTime);
#endif
}

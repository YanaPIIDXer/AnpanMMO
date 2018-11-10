#include "stdafx.h"
#include "TickManager.h"
#if WIN32
#include <time.h>
#else
#include <sys/time.h>
#endif

TickManager TickManager::Instance;

// �R���X�g���N�^
TickManager::TickManager()
{
	timespec_get(&PrevTime, TIME_UTC);
}

// ���t���[���̏���.
void TickManager::Poll()
{
	timespec CurrentTime;
	timespec_get(&CurrentTime, TIME_UTC);
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

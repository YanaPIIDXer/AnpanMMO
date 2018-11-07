#include "stdafx.h"
#include "TickManager.h"
#include <ctime>

TickManager TickManager::Instance;

// �R���X�g���N�^
TickManager::TickManager()
{
	PrevTime = clock();
}

// ���t���[���̏���.
void TickManager::Poll()
{
	int CurrentTime = clock();
	int DeltaTime = CurrentTime - PrevTime;

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

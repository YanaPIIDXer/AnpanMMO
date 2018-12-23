/**
 * @file ExecuterPool.cpp
 * @brief �X�N���v�g���s�I�u�W�F�N�g�v�[��
 * @author YanaP
 */

#include "ExecuterPool.h"
#include "ScriptExecuterBase.h"

ExecuterPool ExecuterPool::Instance;

// �R���X�g���N�^
ExecuterPool::ExecuterPool()
	: NextId(1)
{
}

// �o�^.
long  ExecuterPool::Register(ScriptExecuterBase *pExecuter)
{
	long Id = NextId;
	Pool[Id] = pExecuter;
	NextId++;
	return Id;
}

// �擾.
ScriptExecuterBase *ExecuterPool::Get(long Id)
{
	if (Pool.find(Id) == Pool.end()) { return NULL; }
	return Pool[Id];
}

// ����.
void ExecuterPool::Remove(long Id)
{
	if (Pool.find(Id) == Pool.end()) { return; }
	Pool.erase(Id);
}

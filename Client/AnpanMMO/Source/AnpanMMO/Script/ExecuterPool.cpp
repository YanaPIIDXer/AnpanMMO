/**
 * @file ExecuterPool.cpp
 * @brief スクリプト実行オブジェクトプール
 * @author YanaP
 */

#include "ExecuterPool.h"
#include "ScriptExecuterBase.h"

ExecuterPool ExecuterPool::Instance;

// コンストラクタ
ExecuterPool::ExecuterPool()
	: NextId(1)
{
}

// 登録.
long  ExecuterPool::Register(ScriptExecuterBase *pExecuter)
{
	long Id = NextId;
	Pool[Id] = pExecuter;
	NextId++;
	return Id;
}

// 取得.
ScriptExecuterBase *ExecuterPool::Get(long Id)
{
	if (Pool.find(Id) == Pool.end()) { return NULL; }
	return Pool[Id];
}

// 消去.
void ExecuterPool::Remove(long Id)
{
	if (Pool.find(Id) == Pool.end()) { return; }
	Pool.erase(Id);
}

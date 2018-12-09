#include "stdafx.h"
#include "ScriptBinds.h"
#include "ScriptExecuterBase.h"
#include "ExecuterPool.h"
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

// ���b�Z�[�W�\��.
int ShowMessage_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	const char *pMessage = luaL_checkstring(pState, -1);
	if (pExecuter == NULL) { return 0; }

	pExecuter->ShowMessage_Impl(pMessage);
	return 0;
}

// �I�������v�b�V��
int PushSelection_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	const char *pMessage = luaL_checkstring(pState, -1);
	pExecuter->PushSelection_Impl(pMessage);
	return 0;
}

// �I������\��.
int ShowSelection_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -1);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	pExecuter->ShowSelection_Impl();
	return 0;
}

// �t���O���Z�b�g
int SetFlag_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	int Flag = (int) luaL_checknumber(pState, -1);
	pExecuter->SetFlag(Flag);
	return 0;
}

// �t���O���擾.
int GetFlag_Call(lua_State *pState)
{
	long Id = (long) luaL_checknumber(pState, -2);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	int Flag = (int) luaL_checknumber(pState, -1);
	bool bFlag = pExecuter->GetFlag(Flag);
	lua_pushboolean(pState, bFlag);

	return 1;
}

#include "stdafx.h"
#include "ScriptBinds.h"
#include "ScriptExecuterBase.h"
#include "ExecuterPool.h"
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

// メッセージ表示.
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

// 選択肢をプッシュ
int PushSelection_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	const char *pMessage = luaL_checkstring(pState, -1);
	pExecuter->PushSelection_Impl(pMessage);
	return 0;
}

// 選択肢を表示.
int ShowSelection_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -1);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	pExecuter->ShowSelection_Impl();
	return 0;
}

// フラグをセット
int SetFlag_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	int Flag = (int) luaL_checknumber(pState, -1);
	pExecuter->SetFlag(Flag);
	return 0;
}

// フラグを取得.
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

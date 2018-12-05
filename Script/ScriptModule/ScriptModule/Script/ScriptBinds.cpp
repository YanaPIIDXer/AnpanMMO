#include "Include/ScriptBinds.h"
#include "Include/ScriptExecuterBase.h"
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

// メッセージ表示.
int ShowMessage_Call(lua_State *pState)
{
	const char *pMessage;
	pMessage = luaL_checkstring(pState, 1);
	ScriptExecuterBase::GetInstance()->ShowMessage_Impl(pMessage);
	return 0;
}

// 選択肢をプッシュ
int PushSelection_Call(lua_State *pState)
{
	const char *pMessage;
	pMessage = luaL_checkstring(pState, 1);
	ScriptExecuterBase::GetInstance()->PushSelection_Impl(pMessage);
	return 0;
}

// 選択肢を表示.
int ShowSelection_Call(lua_State *pState)
{
	ScriptExecuterBase::GetInstance()->ShowSelection_Impl();
	return 0;
}

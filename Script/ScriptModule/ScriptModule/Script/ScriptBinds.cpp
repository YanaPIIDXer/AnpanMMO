#include "Include/ScriptBinds.h"
#include "Include/ScriptExecuterBase.h"
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

// メッセージ表示.
int ShowMessage_Call(lua_State *pState)
{
	const char *pMessage = luaL_checkstring(pState, 1);
	ScriptExecuterBase::GetInstance()->ShowMessage_Impl(pMessage);
	return 0;
}

// 選択肢をプッシュ
int PushSelection_Call(lua_State *pState)
{
	const char *pMessage = luaL_checkstring(pState, 1);
	ScriptExecuterBase::GetInstance()->PushSelection_Impl(pMessage);
	return 0;
}

// 選択肢を表示.
int ShowSelection_Call(lua_State *pState)
{
	ScriptExecuterBase::GetInstance()->ShowSelection_Impl();
	return 0;
}

// フラグをセット
int SetFlag_Call(lua_State *pState)
{
	const char *pFlagName = luaL_checkstring(pState, 1);
	ScriptExecuterBase::GetInstance()->SetFlag(pFlagName);
	return 0;
}

// フラグを取得.
int GetFlag_Call(lua_State *pState)
{
	const char *pFlagName = luaL_checkstring(pState, 1);
	bool bFlag = ScriptExecuterBase::GetInstance()->GetFlag(pFlagName);
	lua_pushboolean(pState, bFlag);

	return 1;
}

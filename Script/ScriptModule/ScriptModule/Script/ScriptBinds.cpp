#include "Include/ScriptBinds.h"
#include "Include/ScriptExecuterBase.h"
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

// ���b�Z�[�W�\��.
int ShowMessage_Call(lua_State *pState)
{
	const char *pMessage;
	pMessage = luaL_checkstring(pState, 1);
	ScriptExecuterBase::GetInstance()->ShowMessage_Impl(pMessage);
	return 0;
}

// �I�������v�b�V��
int PushSelection_Call(lua_State *pState)
{
	const char *pMessage;
	pMessage = luaL_checkstring(pState, 1);
	ScriptExecuterBase::GetInstance()->PushSelection_Impl(pMessage);
	return 0;
}

// �I������\��.
int ShowSelection_Call(lua_State *pState)
{
	ScriptExecuterBase::GetInstance()->ShowSelection_Impl();
	return 0;
}

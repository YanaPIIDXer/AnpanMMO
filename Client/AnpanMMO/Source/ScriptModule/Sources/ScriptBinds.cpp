#include "Include/ScriptBinds.h"
#include "Include/ScriptExecuterBase.h"
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

// ���b�Z�[�W�\��.
int ShowMessage_Call(lua_State *pState)
{
	const char *pMessage = luaL_checkstring(pState, 1);
	ScriptExecuterBase::GetInstance()->ShowMessage_Impl(pMessage);
	return 0;
}

// �I�������v�b�V��
int PushSelection_Call(lua_State *pState)
{
	const char *pMessage = luaL_checkstring(pState, 1);
	ScriptExecuterBase::GetInstance()->PushSelection_Impl(pMessage);
	return 0;
}

// �I������\��.
int ShowSelection_Call(lua_State *pState)
{
	ScriptExecuterBase::GetInstance()->ShowSelection_Impl();
	return 0;
}

// �t���O���Z�b�g
int SetFlag_Call(lua_State *pState)
{
	const char *pFlagName = luaL_checkstring(pState, 1);
	ScriptExecuterBase::GetInstance()->SetFlag(pFlagName);
	return 0;
}

// �t���O���擾.
int GetFlag_Call(lua_State *pState)
{
	const char *pFlagName = luaL_checkstring(pState, 1);
	bool bFlag = ScriptExecuterBase::GetInstance()->GetFlag(pFlagName);
	lua_pushboolean(pState, bFlag);

	return 1;
}

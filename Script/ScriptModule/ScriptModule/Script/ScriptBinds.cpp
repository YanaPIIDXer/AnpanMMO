#include "Include/ScriptBinds.h"
#include "Include/ScriptExecuterBase.h"

// メッセージ表示.
int ShowMessage_Call(lua_State *pState)
{
	const char *pMessage;
	pMessage = lua_tostring(pState ,1);
	lua_pop(pState, lua_gettop(pState));
	ScriptExecuterBase::GetInstance()->ShowMessage_Impl(pMessage);
	return 0;
}

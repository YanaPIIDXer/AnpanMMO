#include <iostream>
#include "Include/ScriptExecuterBase.h"

// コンストラクタ
ScriptExecuterBase::ScriptExecuterBase()
{
	pState = luaL_newstate();
	luaL_openlibs(pState);
	luaopen_base(pState);
	pCoroutineState = lua_newthread(pState);
	BindFunctions();
}

// デストラクタ
ScriptExecuterBase::~ScriptExecuterBase()
{
	lua_close(pState);
}

// スクリプトをセット。
void ScriptExecuterBase::SetScript(const char *pScript)
{
	luaL_dostring(pState, pScript);
}

// スクリプトの実行を再開。
void ScriptExecuterBase::Resume()
{
	lua_resume(pState, pCoroutineState, 0);
}


// 関数をバインド。
void ScriptExecuterBase::BindFunctions()
{
	lua_getglobal(pCoroutineState, "ShowMessage");
}

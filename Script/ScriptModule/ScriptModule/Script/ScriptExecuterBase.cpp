#include <iostream>
#include "Include/ScriptExecuterBase.h"

// コンストラクタ
ScriptExecuterBase::ScriptExecuterBase()
{
	pState = luaL_newstate();
	luaL_openlibs(pState);
}

// デストラクタ
ScriptExecuterBase::~ScriptExecuterBase()
{
	lua_close(pState);
}

// テスト実行.
void ScriptExecuterBase::ExecuteTest()
{
	luaL_dostring(pState, "print(\"Execute Test\")");
	lua_pcall(pState, 0, 0, 0);
}

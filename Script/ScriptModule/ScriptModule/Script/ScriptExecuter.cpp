#include <iostream>
#include "Include/ScriptExecuter.h"

ScriptExecuter ScriptExecuter::Instance;

// コンストラクタ
ScriptExecuter::ScriptExecuter()
{
	pState = luaL_newstate();
	luaL_openlibs(pState);
}

// デストラクタ
ScriptExecuter::~ScriptExecuter()
{
	lua_close(pState);
}

// テスト実行.
void ScriptExecuter::ExecuteTest()
{
	luaL_dostring(pState, "print(\"Execute Test\")");
	lua_pcall(pState, 0, 0, 0);
}

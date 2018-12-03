#include <iostream>
#include "Include/ScriptExecuter.h"

ScriptExecuter ScriptExecuter::Instance;

// �R���X�g���N�^
ScriptExecuter::ScriptExecuter()
{
	pState = luaL_newstate();
	luaL_openlibs(pState);
}

// �f�X�g���N�^
ScriptExecuter::~ScriptExecuter()
{
	lua_close(pState);
}

// �e�X�g���s.
void ScriptExecuter::ExecuteTest()
{
	luaL_dostring(pState, "print(\"Execute Test\")");
	lua_pcall(pState, 0, 0, 0);
}

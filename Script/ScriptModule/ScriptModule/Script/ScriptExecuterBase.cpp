#include <iostream>
#include "Include/ScriptExecuterBase.h"

// �R���X�g���N�^
ScriptExecuterBase::ScriptExecuterBase()
{
	pState = luaL_newstate();
	luaL_openlibs(pState);
}

// �f�X�g���N�^
ScriptExecuterBase::~ScriptExecuterBase()
{
	lua_close(pState);
}

// �e�X�g���s.
void ScriptExecuterBase::ExecuteTest()
{
	luaL_dostring(pState, "print(\"Execute Test\")");
	lua_pcall(pState, 0, 0, 0);
}

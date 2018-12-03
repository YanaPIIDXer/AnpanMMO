#include <iostream>
#include "Include/ScriptExecuterBase.h"

// �R���X�g���N�^
ScriptExecuterBase::ScriptExecuterBase()
{
	pState = luaL_newstate();
	luaL_openlibs(pState);
	luaopen_base(pState);
	pCoroutineState = lua_newthread(pState);
	BindFunctions();
}

// �f�X�g���N�^
ScriptExecuterBase::~ScriptExecuterBase()
{
	lua_close(pState);
}

// �X�N���v�g���Z�b�g�B
void ScriptExecuterBase::SetScript(const char *pScript)
{
	luaL_dostring(pState, pScript);
}

// �X�N���v�g�̎��s���ĊJ�B
void ScriptExecuterBase::Resume()
{
	lua_resume(pState, pCoroutineState, 0);
}


// �֐����o�C���h�B
void ScriptExecuterBase::BindFunctions()
{
	lua_getglobal(pCoroutineState, "ShowMessage");
}

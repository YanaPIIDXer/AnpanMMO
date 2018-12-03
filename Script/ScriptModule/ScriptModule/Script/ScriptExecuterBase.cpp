#include <iostream>
#include "Include/ScriptExecuterBase.h"
#include <functional>
#include "Include/ScriptBinds.h"

ScriptExecuterBase *ScriptExecuterBase::pInstance = NULL;

// �R���X�g���N�^
ScriptExecuterBase::ScriptExecuterBase()
{
	pInstance = this;
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

// �X�N���v�g�����s�B
void ScriptExecuterBase::ExecuteScript(const char *pScript)
{
	std::string Script = "";
	
	// �֐���`��������include����B
	Script += "dofile( 'Functions.lua' )\n";
	Script += pScript;

	luaL_dostring(pState, Script.c_str());
	if (lua_pcall(pState, 0, 0, 0))
	{
		std::cout << lua_tostring(pState, -1) << std::endl;
	}
}

// �X�N���v�g�̎��s���ĊJ�B
void ScriptExecuterBase::Resume()
{
	lua_resume(pState, pCoroutineState, 0);
}


// �֐����o�C���h�B
void ScriptExecuterBase::BindFunctions()
{
	// ���b�Z�[�W�\��.
	lua_register(pCoroutineState, "ShowMessage", ShowMessage_Call);
}

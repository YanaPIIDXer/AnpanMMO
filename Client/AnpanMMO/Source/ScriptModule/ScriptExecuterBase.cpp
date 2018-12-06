#include "ScriptExecuterBase.h"
#include <iostream>
#include <functional>
#include "ScriptBinds.h"
#include "ExecuterPool.h"

// �R���X�g���N�^
ScriptExecuterBase::ScriptExecuterBase()
	: pCoroutineState(NULL)
	, CoroutineRef(0)
	, ScriptDir("")
	, Id(0)
{
	pState = luaL_newstate();
	luaL_openlibs(pState);
	luaopen_base(pState);
	BindFunctions();
}

// �f�X�g���N�^
ScriptExecuterBase::~ScriptExecuterBase()
{
	ExecuterPool::GetInstance().Remove(Id);
	lua_close(pState);
}

// �X�N���v�g�����s�B
void ScriptExecuterBase::ExecuteScript(const char *pScript)
{
	// �֐���`��������include����B
	std::string Include = "dofile( '";
	Include += ScriptDir;
	Include += "/Functions.lua' )\n";

	// �f�B���N�g����؂蕶���Ƃ��āu\�v�������Ă������̂��߂̑Ώ��B
	size_t Pos = Include.find("\\");
	while (Pos != std::string::npos)
	{
		Include = Include.replace(Pos, 1, "/");
		Pos = Include.find("\\");
	}

	// �X�N���v�g�̓��e���R���[�`����.
	std::string Script = "colo = coroutine.create(\n";
	Script += "function()\n";
	Script += pScript;
	Script += "\nend";
	Script += "\n)\n";

	// �I�����p�ɃO���[�o���ϐ���p�ӁB
	Script += "Selected = 0\n";

	// �R���[�`���̎��s�֐�.
	Script += "repeat\n";
	Script += "coroutine.resume(colo, 0)\n";
	Script += "until coroutine.status(colo) == \"dead\"\n";

	Script = Include + Script;

	if (luaL_loadstring(pState, Script.c_str()))
	{
		std::string ErrorMsg = "LoadString Error:";
		ErrorMsg += lua_tostring(pState, -1);
		OnExecuteError(ErrorMsg);
		return;
	}

	// �R���[�`���̐���.
	int Top = lua_gettop(pState);
	if (pCoroutineState != NULL && CoroutineRef != 0)
	{
		luaL_unref(pState, LUA_REGISTRYINDEX, CoroutineRef);

		pCoroutineState = NULL;
		CoroutineRef = 0;
	}
	pCoroutineState = lua_newthread(pState);
	CoroutineRef = luaL_ref(pState, LUA_REGISTRYINDEX);
	lua_settop(pState, Top);

	// �������g�i�̂h�c�j��o�^�B
	Id = ExecuterPool::GetInstance().Register(this);
	lua_pushnumber(pState, Id);
	lua_setglobal(pState, "this");

	// ���s�J�n�B
	lua_resume(pState, pCoroutineState, 0);
}

// �X�N���v�g�̎��s���ĊJ�B
void ScriptExecuterBase::Resume()
{
	lua_resume(pState, pCoroutineState, 0);
}

// �I�������I�����ꂽ�B
void ScriptExecuterBase::OnSelectedSelection(int Index)
{
	lua_pushnumber(pState, Index);
	lua_setglobal(pState, "Selected");
	Resume();
}


// �֐��Q���o�C���h�B
void ScriptExecuterBase::BindFunctions()
{
	BindFunction(ShowMessage_Call, "ShowMessage_Impl");
	BindFunction(PushSelection_Call, "PushSelection_Impl");
	BindFunction(ShowSelection_Call, "ShowSelection_Impl");
	BindFunction(SetFlag_Call, "SetFlag_Impl");
	BindFunction(GetFlag_Call, "GetFlag_Impl");
}

// �֐����o�C���h�B
void ScriptExecuterBase::BindFunction(lua_CFunction Func, const char *pName	)
{
	lua_register(pState, pName, Func);
}
#include "ScriptExecuterBase.h"
#include <iostream>
#include <stdio.h>
#include <functional>
#include "ScriptBinds.h"
#include "ExecuterPool.h"

// �R���X�g���N�^
ScriptExecuterBase::ScriptExecuterBase()
	: pState(NULL)
	, pCoroutineState(NULL)
	, CoroutineRef(0)
	, ScriptDir("")
	, Id(0)
	, bIsFinished(false)
{
}

// �f�X�g���N�^
ScriptExecuterBase::~ScriptExecuterBase()
{
	ExecuterPool::GetInstance().Remove(Id);
	CloseState();
}

// �X�N���v�g�����s�B
void ScriptExecuterBase::ExecuteScript(const char *pScript)
{
	CreateState();

	// �֐���`��������include����B
	std::string Include = "dofile( '";
	Include += ScriptDir;
	Include += "/Functions.lua' )\n";

	// �t���O��`��������include����B
	Include += "dofile( '";
	Include += ScriptDir;
	Include += "/Flags.lua' )\n";

	// �f�B���N�g����؂蕶���Ƃ��āu\�v�������Ă������̂��߂̑Ώ��B
	size_t Pos = Include.find("\\");
	while (Pos != std::string::npos)
	{
		Include = Include.replace(Pos, 1, "/");
		Pos = Include.find("\\");
	}

	// �X�N���v�g�̓��e���R���[�`����.
	std::string Script = "function main()\n";
	Script += pScript;
	Script += "\nreturn 0\n";
	Script += "end\n";

	// �I�����p�ɃO���[�o���ϐ���p�ӁB
	Script += "Selected = 0\n";

	Script = Include + Script;

	if (IsServer())
	{
		// �T�[�o��ł͓������Ȃ����̂̓R�����g�A�E�g�B
		CommentOutWithServerMode(Script);
	}

	if (luaL_dostring(pState, Script.c_str()))
	{
		std::string ErrorMsg = "DoString Error:";
		ErrorMsg += lua_tostring(pState, -1);
		OnExecuteError(ErrorMsg);
		return;
	}

	// �������g�i�̂h�c�j��o�^�B
	if (Id == 0)
	{
		Id = ExecuterPool::GetInstance().Register(this);
	}
	lua_pushnumber(pState, Id);
	lua_setglobal(pState, "this");

	lua_settop(pState, 0);

	// �R���[�`���̐���.
	pCoroutineState = lua_newthread(pState);
	lua_getglobal(pState, "main");

	bIsFinished = false;

	// ���s�J�n�B
	Resume();
}

// �X�N���v�g�̎��s���ĊJ�B
void ScriptExecuterBase::Resume()
{
	lua_resume(pState, pCoroutineState, 0);
	if (!lua_isnumber(pState, -1))
	{
		std::string ErrorMsg = "Execute Error:";
		ErrorMsg += lua_tostring(pState, -1);
		OnExecuteError(ErrorMsg);
		return;
	}
	int Ret = lua_tointeger(pState, -1);
	if (Ret == 0)
	{
		CloseState();
		bIsFinished = true;
		OnFinished();
	}
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

// State�𐶐�.
void ScriptExecuterBase::CreateState()
{
	if (pState != NULL)
	{
		CloseState();
	}

	pState = luaL_newstate();
	luaL_openlibs(pState);
	luaopen_base(pState);
	BindFunctions();
}

// State��Close
void ScriptExecuterBase::CloseState()
{
	if (pState == NULL) { return; }

	lua_close(pState);	
	pState = NULL;
}

// �T�[�o���[�h�œ������Ă��鎞�͓������Ȃ����̂��R�����g�A�E�g
void ScriptExecuterBase::CommentOutWithServerMode(std::string &Code)
{
	CommentOutFunction(Code, "ShowMessage");
}

// �֐��̃R�����g�A�E�g
void ScriptExecuterBase::CommentOutFunction(std::string &Code, const std::string &FunctionName)
{
	size_t Pos = Code.find(FunctionName);
	while (Pos != std::string::npos)
	{
		Code = Code.replace(Pos, FunctionName.length(), "--" + FunctionName);
		Pos = Code.find(FunctionName, Pos + FunctionName.length() + 2);
	}
}

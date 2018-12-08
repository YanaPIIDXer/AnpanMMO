#include "ScriptExecuterBase.h"
#include <iostream>
#include <functional>
#include "ScriptBinds.h"
#include "ExecuterPool.h"

// コンストラクタ
ScriptExecuterBase::ScriptExecuterBase()
	: pState(NULL)
	, pCoroutineState(NULL)
	, CoroutineRef(0)
	, ScriptDir("")
	, Id(0)
{
}

// デストラクタ
ScriptExecuterBase::~ScriptExecuterBase()
{
	ExecuterPool::GetInstance().Remove(Id);
	CloseState();
}

// スクリプトを実行。
void ScriptExecuterBase::ExecuteScript(const char *pScript)
{
	CreateState();

	// 関数定義を自動でincludeする。
	std::string Include = "dofile( '";
	Include += ScriptDir;
	Include += "/Functions.lua' )\n";

	// ディレクトリ区切り文字として「\」が入ってきた時のための対処。
	size_t Pos = Include.find("\\");
	while (Pos != std::string::npos)
	{
		Include = Include.replace(Pos, 1, "/");
		Pos = Include.find("\\");
	}

	// スクリプトの内容をコルーチン化.
	std::string Script = "function main()\n";
	Script += pScript;
	Script += "\nreturn 1\n";
	Script += "end\n";

	// 選択肢用にグローバル変数を用意。
	Script += "Selected = 0\n";

	Script = Include + Script;

	if (luaL_dostring(pState, Script.c_str()))
	{
		std::string ErrorMsg = "DoString Error:";
		ErrorMsg += lua_tostring(pState, -1);
		OnExecuteError(ErrorMsg);
		return;
	}

	// 自分自身（のＩＤ）を登録。
	if (Id == 0)
	{
		Id = ExecuterPool::GetInstance().Register(this);
	}
	lua_pushnumber(pState, Id);
	lua_setglobal(pState, "this");

	// コルーチンの生成.
	pCoroutineState = lua_newthread(pState);
	lua_getglobal(pState, "main");

	// 実行開始。
	Resume();
}

// スクリプトの実行を再開。
void ScriptExecuterBase::Resume()
{
	lua_resume(pState, pCoroutineState, 0);
	int Ret = lua_tointeger(pState, -1);
	if (Ret == 0)
	{
		CloseState();
		OnFinished();
	}
}

// 選択肢が選択された。
void ScriptExecuterBase::OnSelectedSelection(int Index)
{
	lua_pushnumber(pState, Index);
	lua_setglobal(pState, "Selected");
}


// 関数群をバインド。
void ScriptExecuterBase::BindFunctions()
{
	BindFunction(ShowMessage_Call, "ShowMessage_Impl");
	BindFunction(PushSelection_Call, "PushSelection_Impl");
	BindFunction(ShowSelection_Call, "ShowSelection_Impl");
	BindFunction(SetFlag_Call, "SetFlag_Impl");
	BindFunction(GetFlag_Call, "GetFlag_Impl");
}

// 関数をバインド。
void ScriptExecuterBase::BindFunction(lua_CFunction Func, const char *pName	)
{
	lua_register(pState, pName, Func);
}

// Stateを生成.
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

// StateをClose
void ScriptExecuterBase::CloseState()
{
	if (pState == NULL) { return; }

	lua_close(pState);	
	pState = NULL;
}

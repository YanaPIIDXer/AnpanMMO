#include "stdafx.h"
#include "ScriptExecuterBase.h"
#include <iostream>
#include <functional>
#include "ScriptBinds.h"
#include "ExecuterPool.h"

// コンストラクタ
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

// デストラクタ
ScriptExecuterBase::~ScriptExecuterBase()
{
	ExecuterPool::GetInstance().Remove(Id);
	lua_close(pState);
}

// スクリプトを実行。
void ScriptExecuterBase::ExecuteScript(const char *pScript)
{
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
	std::string Script = "colo = coroutine.create(\n";
	Script += "function()\n";
	Script += pScript;
	Script += "\nend";
	Script += "\n)\n";

	// 選択肢用にグローバル変数を用意。
	Script += "Selected = 0\n";

	// コルーチンの実行関数.
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

	// コルーチンの生成.
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

	// 自分自身（のＩＤ）を登録。
	Id = ExecuterPool::GetInstance().Register(this);
	lua_pushnumber(pState, Id);
	lua_setglobal(pState, "this");

	// 実行開始。
	lua_resume(pState, pCoroutineState, 0);
}

// スクリプトの実行を再開。
void ScriptExecuterBase::Resume()
{
	lua_resume(pState, pCoroutineState, 0);
}

// 選択肢が選択された。
void ScriptExecuterBase::OnSelectedSelection(int Index)
{
	lua_pushnumber(pState, Index);
	lua_setglobal(pState, "Selected");
	Resume();
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

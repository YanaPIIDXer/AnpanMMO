#include "ScriptExecuterBase.h"
#include <iostream>
#include <functional>
#include "ScriptBinds.h"
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

ScriptExecuterBase *ScriptExecuterBase::pInstance = NULL;

// コンストラクタ
ScriptExecuterBase::ScriptExecuterBase()
	: pCoroutineState(NULL)
	, CoroutineRef(0)
	, ScriptDir("")
{
	pInstance = this;
	pState = luaL_newstate();
	luaL_openlibs(pState);
	luaopen_base(pState);
	BindFunctions();
}

// デストラクタ
ScriptExecuterBase::~ScriptExecuterBase()
{
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
	Script += "Selected = 0";

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


// 関数をバインド。
void ScriptExecuterBase::BindFunctions()
{
	// メッセージ表示.ri
	lua_register(pState, "ShowMessage_Impl", ShowMessage_Call);
	lua_register(pState, "PushSelection_Impl", PushSelection_Call);
	lua_register(pState, "ShowSelection_Impl", ShowSelection_Call);
	lua_register(pState, "SetFlag_Impl", SetFlag_Call);
	lua_register(pState, "GetFlag_Impl", GetFlag_Call);
}

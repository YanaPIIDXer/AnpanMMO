#include <iostream>
#include "Include/ScriptExecuterBase.h"
#include <functional>
#include "Include/ScriptBinds.h"

ScriptExecuterBase *ScriptExecuterBase::pInstance = NULL;

// コンストラクタ
ScriptExecuterBase::ScriptExecuterBase()
{
	pInstance = this;
	pState = luaL_newstate();
	luaL_openlibs(pState);
	luaopen_base(pState);
	pCoroutineState = lua_newthread(pState);
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
	std::string Script = "";
	
	// 関数定義を自動でincludeする。
	Script += "dofile( 'Functions.lua' )\n";
	Script += pScript;

	luaL_dostring(pState, Script.c_str());
	if (lua_pcall(pState, 0, 0, 0))
	{
		std::cout << lua_tostring(pState, -1) << std::endl;
	}
}

// スクリプトの実行を再開。
void ScriptExecuterBase::Resume()
{
	lua_resume(pState, pCoroutineState, 0);
}


// 関数をバインド。
void ScriptExecuterBase::BindFunctions()
{
	// メッセージ表示.
	lua_register(pCoroutineState, "ShowMessage", ShowMessage_Call);
}

#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

/**
 * スクリプト実行クラス
 */
class ScriptExecuter
{

public:

	// デストラクタ
	~ScriptExecuter();

	// テスト実行.
	void ExecuteTest();

private:

	// Luaステート
	lua_State *pState;

	// ======== Singleton ==========
public:

	static ScriptExecuter &GetInstnace() { return Instance; }

private:

	ScriptExecuter();
	static ScriptExecuter Instance;

};

#endif		// #ifndef __SCRIPTEXECUTER_H__
	
#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

/**
 * スクリプト実行クラス
 */
class ScriptExecuterBase
{

public:

	// コンストラクタ
	ScriptExecuterBase();

	// デストラクタ
	virtual ~ScriptExecuterBase();

	// テスト実行.
	void ExecuteTest();

private:

	// Luaステート
	lua_State *pState;

};

#endif		// #ifndef __SCRIPTEXECUTER_H__
	
#ifndef __SCRIPTEXECUTERBASE_H__
#define __SCRIPTEXECUTERBASE_H__

#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

/**
 * スクリプト実行基底クラス
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

	// メッセージを表示.
	virtual void ShowMessage() = 0;

private:

	// Luaステート
	lua_State *pState;

};

#endif		// #ifndef __SCRIPTEXECUTERBASE_H__
	
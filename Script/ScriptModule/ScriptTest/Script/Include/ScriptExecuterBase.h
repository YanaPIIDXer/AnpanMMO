#ifndef __SCRIPTEXECUTERBASE_H__
#define __SCRIPTEXECUTERBASE_H__

#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"
#include <string>

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

	// スクリプトをセット。
	void SetScript(const char *pScript);

	// スクリプトの実行を再開.
	void Resume();

	// メッセージを表示.
	virtual void ShowMessage(const std::string &Message) = 0;

private:

	// Luaステート
	lua_State *pState;

	// コルーチン用State
	lua_State *pCoroutineState;


	// 関数をバインド。
	void BindFunctions();

};

#endif		// #ifndef __SCRIPTEXECUTERBASE_H__
	
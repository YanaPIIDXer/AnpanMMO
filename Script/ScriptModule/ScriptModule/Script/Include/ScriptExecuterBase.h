#ifndef __SCRIPTEXECUTERBASE_H__
#define __SCRIPTEXECUTERBASE_H__

#include <string>

struct lua_State;

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

	// スクリプトを実行。
	void ExecuteScript(const char *pScriptDir, const char *pScript);

	// スクリプトの実行を再開.
	void Resume();

	// メッセージを表示.
	virtual void ShowMessage_Impl(const std::string &Message) = 0;

protected:

	// 実行エラー
	virtual void OnExecuteError(const std::string &ErrorMessage) = 0;

private:

	// Luaステート
	lua_State *pState;

	// コルーチン用State
	lua_State *pCoroutineState;


	// 関数をバインド。
	void BindFunctions();

	// ========= Singletonもどき =============
public:

	static ScriptExecuterBase *GetInstance() { return pInstance; }

private:

	static ScriptExecuterBase *pInstance;

};

#endif		// #ifndef __SCRIPTEXECUTERBASE_H__
	
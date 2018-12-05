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

	// スクリプトが格納されたディレクトリを設定。
	void SetScriptDir(const char *pScriptDir) { ScriptDir = pScriptDir; }

	// スクリプトを実行。
	void ExecuteScript(const char *pScript);

	// スクリプトの実行を再開.
	void Resume();

	// メッセージを表示.
	virtual void ShowMessage_Impl(const std::string &Message) = 0;

	// 選択肢がプッシュされた。
	virtual void PushSelection_Impl(const std::string &Message) = 0;

	// 選択肢表示.
	virtual void ShowSelection_Impl() = 0;

	// 選択肢が選択された。
	void OnSelectedSelection(int Index);

	// フラグをセット
	virtual void SetFlag(const char *pFlagName) = 0;

	// フラグを取得.
	virtual bool GetFlag(const char *pFlagName) = 0;

protected:

	// 実行エラー
	virtual void OnExecuteError(const std::string &ErrorMessage) = 0;

private:

	// Luaステート
	lua_State *pState;

	// コルーチン用State
	lua_State *pCoroutineState;

	// コルーチンの参照.
	int CoroutineRef;

	// スクリプトが格納されたディレクトリ
	std::string ScriptDir;


	// 関数をバインド。
	void BindFunctions();

	// ========= Singletonもどき =============
public:

	static ScriptExecuterBase *GetInstance() { return pInstance; }

private:

	static ScriptExecuterBase *pInstance;

};

#endif		// #ifndef __SCRIPTEXECUTERBASE_H__
	
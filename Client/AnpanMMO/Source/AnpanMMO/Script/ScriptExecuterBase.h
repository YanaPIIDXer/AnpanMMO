#ifndef __SCRIPTEXECUTERBASE_H__
#define __SCRIPTEXECUTERBASE_H__

#include <string>
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

/**
 * スクリプト実行基底クラス
 */
class ANPANMMO_API ScriptExecuterBase
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

	// 終了しているか？
	bool IsFinished() const { return bIsFinished; }

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

	// 処理が終了した。
	virtual void OnFinished() = 0;
	
	// デバッグメッセージを表示.
	virtual void ShowDebugMessage(const std::string &Message) = 0;

	// サーバモードか？
	virtual bool IsServer() const = 0;

private:

	// Luaステート
	lua_State *pState;

	// コルーチン用State
	lua_State *pCoroutineState;

	// コルーチンの参照.
	int CoroutineRef;

	// スクリプトが格納されたディレクトリ
	std::string ScriptDir;

	// ID
	long Id;

	// 終了しているか？
	bool bIsFinished;


	// 関数群をバインド。
	void BindFunctions();

	// 関数をバインド。
	void BindFunction(lua_CFunction Func, const char *pName);

	// Stateを生成.
	void CreateState();

	// StateをClose
	void CloseState();

	// サーバモードで動かしている時は動かさないものをコメントアウト
	void CommentOutWithServerMode(std::string &Code);

	// 関数のコメントアウト
	void CommentOutFunction(std::string &Code, const std::string &FunctionName);

};

#endif		// #ifndef __SCRIPTEXECUTERBASE_H__

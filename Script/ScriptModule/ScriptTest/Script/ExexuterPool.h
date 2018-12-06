#ifndef __EXECUTERPOOL_H__
#define __EXECUTERPOOL_H__

#include <map>

struct lua_State;
class ScriptExecuterBase;

/**
 * スクリプト実行オブジェクトプール
 * Luaはメンバ関数をバインド出来ない為、それを解決するためのクラス。
 * サーバの場合、Executerが複数生成されるため、Singletonでの対処では問題が出る。
 */
class ExecuterPool
{

public:

	// デストラクタ
	~ExecuterPool() {}

	// 登録.
	void Register(ScriptExecuterBase *pExecuter, lua_State *pState);

	// 取得.
	ScriptExecuterBase *Get(lua_State *pState);

	// 削除.
	void Remove(lua_State *pState);

private:

	// プール
	std::map<lua_State *, ScriptExecuterBase *> Pool;

	// ======= Singleton =========
public:

	static ExecuterPool &GetInstance() { return Instance; }

private:

	ExecuterPool();
	static ExecuterPool Instance;

};

#endif		// #ifndef __EXECUTERPOOL_H__

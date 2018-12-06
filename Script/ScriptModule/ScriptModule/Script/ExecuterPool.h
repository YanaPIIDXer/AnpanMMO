#ifndef __EXECUTERPOOL_H__
#define __EXECUTERPOOL_H__

#include <map>

class ScriptExecuterBase;

/**
 * スクリプト実行オブジェクトプール
 * クラスのメンバ関数がバインド出来ない関係で作られた。
 * IDとスクリプト実行オブジェクトを紐付け、
 * スクリプトからC++側の関数を呼び出す際は引数にIDを渡すようにする。
 * （ポインタのようなもの）
 */
class ExecuterPool
{

public:

	// デストラクタ
	~ExecuterPool() {}

	// 登録.
	long Register(ScriptExecuterBase *pExecuter);

	// 取得.
	ScriptExecuterBase *Get(long Id);

	// 消去.
	void Remove(long Id);

private:

	// プール
	std::map<long, ScriptExecuterBase *> Pool;

	// 次に割り振られるID
	long NextId;

	// ========== Singleton ============
public:

	static ExecuterPool &GetInstance() { return Instance; }

private:

	ExecuterPool();
	static ExecuterPool Instance;

};

#endif		// #ifndef __EXECUTERPOOL_H__

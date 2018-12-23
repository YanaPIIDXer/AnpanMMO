/**
 * @file ExecuterPool.h
 * @brief スクリプト実行オブジェクトプール
 * @author YanaP
 */
#ifndef __EXECUTERPOOL_H__
#define __EXECUTERPOOL_H__

#include <map>

class ScriptExecuterBase;

/**
 * @class ExecuterPool
 * @brief スクリプト実行オブジェクトプール
 * @details クラスのメンバ関数がバインド出来ない関係で作られた。
 *			IDとスクリプト実行オブジェクトを紐付け、
 *			スクリプトからC++側の関数を呼び出す際は引数にIDを渡すようにする。
 *			（ポインタのようなもの）
 *			シングルトンクラス
 */
class ExecuterPool
{

public:

	/**
	 * @brief デストラクタ
	 */
	~ExecuterPool() {}

	/**
	 * @fn long Register(ScriptExecuterBase *pExecuter)
	 * @brief 登録
	 * @param[in] スクリプト実行クラスへのポインタ
	 * @return ＩＤ
	 */
	long Register(ScriptExecuterBase *pExecuter);

	/*
	 * @fn ScriptExecuterBase *Get(long Id)
	 * @brief 取得
	 * @param[in] Id ID
	 * @return スクリプト実行クラスへのポインタ
	 */
	ScriptExecuterBase *Get(long Id);

	/**
	 * @fn void Remove(long Id)
	 * @brief 消去
	 * @param[in] Id ID
	 */
	void Remove(long Id);

private:

	// プール
	std::map<long, ScriptExecuterBase *> Pool;

	// 次に割り振られるID
	long NextId;

	// ========== Singleton ============
public:

	/**
	 * @fn static ExecuterPool &GetInstance()
	 * @brief シングルトンインスタンスを取得
	 * @return インスタンス
	 */
	static ExecuterPool &GetInstance() { return Instance; }

private:

	ExecuterPool();
	static ExecuterPool Instance;

};

#endif		// #ifndef __EXECUTERPOOL_H__

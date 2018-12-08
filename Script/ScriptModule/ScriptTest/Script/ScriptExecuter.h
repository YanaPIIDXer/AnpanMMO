#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "ScriptExecuterBase.h"
#include <vector>
#include <map>

/**
 * スクリプト実行クラス
 */
class ScriptExecuter : public ScriptExecuterBase
{

public:

	// コンストラクタ
	ScriptExecuter();

	// デストラクタ
	virtual ~ScriptExecuter() {}

	// メッセージ表示。
	virtual void ShowMessage_Impl(const std::string &Message);

	// 選択肢をプッシュ
	virtual void PushSelection_Impl(const std::string &Message);

	// 選択肢を表示.
	virtual void ShowSelection_Impl();
	
	// フラグをセット
	virtual void SetFlag(const char *pFlagName) { FlagMap[pFlagName] = true; }

	// フラグを取得.
	virtual bool GetFlag(const char *pFlagName) { return FlagMap[pFlagName]; }

protected:

	// 実行エラー
	virtual void OnExecuteError(const std::string &Message);

	// 終了した。
	virtual void OnFinished();

	// デバッグメッセージ表示.
	virtual void ShowDebugMessage(const std::string &Message);

private:

	// 選択肢リスト
	std::string Selections[10];

	// 選択肢の数。
	int SelectionCount;

	// フラグマップ
	std::map<const char*, bool> FlagMap;

};

#endif		// #ifndef __SCRIPTEXECUTER_H__

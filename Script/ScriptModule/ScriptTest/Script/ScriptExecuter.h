#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "Include/ScriptExecuterBase.h"
#include <vector>

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

protected:

	// 実行エラー
	virtual void OnExecuteError(const std::string &Message);

private:

	// 選択肢リスト
	std::vector<std::string> Selections;

};

#endif		// #ifndef __SCRIPTEXECUTER_H__

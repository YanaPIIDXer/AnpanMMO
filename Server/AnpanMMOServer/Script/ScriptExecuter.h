#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "ScriptExecuterBase.h"

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

	// メッセージを表示.
	virtual void ShowMessage_Impl(const std::string &Message) {}

	// 選択肢がプッシュされた。
	virtual void PushSelection_Impl(const std::string &Message) {}

	// 選択肢表示.
	virtual void ShowSelection_Impl() {}

	// フラグをセット
	virtual void SetFlag(const char *pFlagName);

	// フラグを取得.
	virtual bool GetFlag(const char *pFlagName);

protected:

	// 実行エラー
	virtual void OnExecuteError(const std::string &ErrorMessage);

	// 処理が終了した。
	virtual void OnFinished() {}

	// デバッグメッセージを表示.
	virtual void ShowDebugMessage(const std::string &Message);

	// サーバモードか？
	virtual bool IsServer() const { return true; }


private:

};

#endif		// #ifndef __SCRIPTEXECUTER_H_

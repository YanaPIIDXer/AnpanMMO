#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "Include/ScriptExecuterBase.h"

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
	virtual void ShowMessage_Impl(const std::string &Message);

protected:

	// 実行エラー
	virtual void OnExecuteError(const std::string &ErrorMessage);

private:

};

#endif		// #ifndef __SCRIPTEXECUTER_H__

// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScriptExecuterBase.h"

/**
 * スクリプト制御クラス
 */
class ANPANMMO_API ScriptExecuter : public ScriptExecuterBase
{

public:

	// コンストラクタ
	ScriptExecuter();

	// デストラクタ
	virtual ~ScriptExecuter() {}

	// スクリプトを実行.
	void RunScript(const FString &FileName);

	// メッセージを表示.
	virtual void ShowMessage_Impl(const std::string &Message) override;

	// 選択肢をプッシュ
	virtual void PushSelection_Impl(const std::string &Message) override;

	// 選択肢を表示.
	virtual void ShowSelection_Impl() override;

	// フラグをセット.
	virtual void SetFlag(const char *pFlagName) override;

	// フラグを取得.
	virtual bool GetFlag(const char *pFlagName) override;

protected:

	// 実行エラー
	virtual void OnExecuteError(const std::string &ErrorMessage) override;

	// 終了した。
	virtual void OnFinished() override;

private:

};

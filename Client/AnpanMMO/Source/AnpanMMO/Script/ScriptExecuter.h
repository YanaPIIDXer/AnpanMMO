// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScriptModule/ScriptExecuterBase.h"

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
	virtual void ShowMessage_Impl(const std::string &Message);

	// 選択肢をプッシュ
	virtual void PushSelection_Impl(const std::string &Message);

	// 選択肢を表示.
	virtual void ShowSelection_Impl();

	// フラグをセット.
	virtual void SetFlag(const char *pFlagName);

	// フラグを取得.
	virtual bool GetFlag(const char *pFlagName);

	// 実行エラー
	virtual void OnExecuteError(const std::string &ErrorMessage);

private:

};

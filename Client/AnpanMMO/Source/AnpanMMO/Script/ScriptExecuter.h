// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScriptExecuterBase.h"

class AActiveGameMode;

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

	// GameModeを設定.
	void SetGameMode(AActiveGameMode *pInGameMode) { pGameMode = pInGameMode; }

	// スクリプトを実行.
	void RunScript(const FString &FileName);

	// メッセージを表示.
	virtual void ShowMessage_Impl(const std::string &Message) override;

	// 選択肢をプッシュ
	virtual void PushSelection_Impl(const std::string &Message) override;

	// 選択肢を表示.
	virtual void ShowSelection_Impl() override;

	// フラグをセット.
	virtual void SetFlag(int Flag) override;

	// フラグを取得.
	virtual bool GetFlag(int Flag) override;

	// ビットフィールドからフラグに変換.
	void ConvertFlagFromBitFields(uint32 BitField1, uint32 BitField2, uint32 BitField3);

protected:

	// 実行エラー
	virtual void OnExecuteError(const std::string &ErrorMessage) override;

	// 終了した。
	virtual void OnFinished() override;

	// デバッグ用メッセージを表示.
	virtual void ShowDebugMessage(const std::string &Message) override;

	// サーバモードか？
	virtual bool IsServer() const override { return false; }

private:

	// GameMode
	TWeakObjectPtr<AActiveGameMode> pGameMode;

	// フラグマップ
	TMap<int32, bool> FlagMap;

};

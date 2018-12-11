// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include <functional>
#include "TitleGameMode.generated.h"

enum PacketID;
class MemoryStreamInterface;
class UTitleScreenWidget;
class UCharacterNameInputWidget;

/**
 * タイトル画面GameMode
 */
UCLASS()
class ANPANMMO_API ATitleGameMode : public AMMOGameModeBase
{

	GENERATED_BODY()

public:

	// コンストラクタ
	ATitleGameMode(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ATitleGameMode() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// ログインリクエストを送信.
	void SendLogInRequest();

protected:

	// ログイン結果.
	UFUNCTION(BlueprintNativeEvent, Category = "LogIn")
	void OnLogInResult(bool bSuccess);
	void OnLogInResult_Implementation(bool bSuccess) {}

private:
	
	// タイトル画面Widget
	UTitleScreenWidget *pScreenWidget;

	// 名前入力Widget
	UCharacterNameInputWidget *pNameInputWidget;


	// 接続コールバック
	void OnConnectResult(bool bConnected);

	// ログイン結果を受信した。
	void OnRecvLogInResult(MemoryStreamInterface *pStream);

	// キャラクタ作成結果を受信した。
	void OnRecvCreateCharacterResult(MemoryStreamInterface *pStream);

	// キャラクタステータスを受信した。
	void OnRecvCharacterStatus(MemoryStreamInterface *pStream);

	// スキルリストを受信した。
	void OnRecvSkillList(MemoryStreamInterface *pStream);

	// スクリプトフラグを受信した。
	void OnRecvScriptFlag(MemoryStreamInterface *pStream);

	// ゲーム画面に進む準備が出来た。
	void OnReadyToGame();
	
};

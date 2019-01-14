// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include <functional>
#include "TitleGameMode.generated.h"

class PacketID;
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
	bool OnRecvLogInResult(MemoryStreamInterface *pStream);

	// キャラクタ作成結果を受信した。
	bool OnRecvCreateCharacterResult(MemoryStreamInterface *pStream);

	// キャラクタステータスを受信した。
	bool OnRecvCharacterStatus(MemoryStreamInterface *pStream);

	// スキルリストを受信した。
	bool OnRecvSkillList(MemoryStreamInterface *pStream);

	// スキルツリーデータを受信した。
	bool OnRecvSkillTreeData(MemoryStreamInterface *pStream);

	// アイテムリストを受信した。
	bool OnRecvItemList(MemoryStreamInterface *pStream);

	// アイテムショートカットを受信した。
	bool OnRecvItemShortcut(MemoryStreamInterface *pStream);

	// スクリプトフラグを受信した。
	bool OnRecvScriptFlag(MemoryStreamInterface *pStream);

	// クエストデータを受信した。
	bool OnRecvQuestData(MemoryStreamInterface *pStream);

	// ゲーム画面に進む準備が出来た。
	void OnReadyToGame();
	
};

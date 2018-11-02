// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Connection/GameServerConnection.h"
#include "MMOGameInstance.generated.h"

class PacketBase;

/**
 * GameInstance
 */
UCLASS()
class ANPANMMO_API UMMOGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	// コンストラクタ
	UMMOGameInstance(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~UMMOGameInstance() {}

	// 終了時の処理.
	virtual void Shutdown() override;

	// 接続.
	bool Connect(const FString &Host, int Port);

	// 切断.
	void Close();

	// 接続されているか？
	bool IsConnected() const { return (pConnection != nullptr && pConnection->IsConnected()); }

	// パケット送信.
	void SendPacket(PacketBase *pPacket);

	// パケット受信delegate取得.
	FOnRecvPacketDelegate GetRecvPacketDelegate() const { return OnRecvPacketDelegate; }

private:

	// ゲームサーバへの接続.
	GameServerConnection *pConnection;

	// パケット受信delegate
	FOnRecvPacketDelegate OnRecvPacketDelegate;


	// パケットを受信した。
	void OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream);
	
};

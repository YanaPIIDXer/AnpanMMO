// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Networking/Public/Networking.h"
#include "Tickable.h"
#include "Buffer.h"

class PacketBase;

/**
 * ゲームサーバ接続.
 */
class GameServerConnection : public FTickableGameObject
{

public:

	// コンストラクタ
	GameServerConnection();

	// デストラクタ
	~GameServerConnection();

	// 接続.
	bool Connect(const FString &Host, int32 Port);

	// 切断.
	void Close();

	// 接続されているか？
	bool IsConnected() const { return (pSocket != nullptr && pSocket->GetConnectionState() == ESocketConnectionState::SCS_Connected); }

	// パケット送信.
	void SendPacket(PacketBase *pPacket);

	// 毎フレームの処理.
	virtual void Tick(float DeltaTime) override;

	// StatID取得.
	virtual TStatId GetStatId() const override { return TStatId(); }

private:

	// Socket
	FSocket *pSocket;

	// 受信バッファ
	Buffer RecvBuffer;

	// 送信バッファ
	Buffer SendBuffer;

	// 受信データサイズ
	static const int32 RecvDataSize;


	// 送信処理.
	void SendProc();

	// 受信処理.
	void RecvProc();

};

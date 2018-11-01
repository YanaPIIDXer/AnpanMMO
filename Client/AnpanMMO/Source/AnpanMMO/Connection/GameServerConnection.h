// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Networking/Public/Networking.h"

/**
 * ゲームサーバ接続.
 */
class GameServerConnection
{

public:

	// コンストラクタ
	GameServerConnection();

	// デストラクタ
	~GameServerConnection();

	// 接続.
	bool Connect(const FString &URL, int32 Port);

	// 切断.
	void Close();

private:

	// Socket
	FSocket *pSocket;

};

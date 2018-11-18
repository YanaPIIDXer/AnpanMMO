// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Connection/GameServerConnection.h"
#include "Character/Player/PlayerStatus.h"
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

	// ステータスを受信した。
	void OnRecvStatus(uint32 Uuid, int32 MaxHp, int32 Atk, int32 Def, int32 Exp);

	// ステータスキャッシュ取得.
	const PlayerStatus &GetStatusCache() const { return StatusCache; }

	// エリアＩＤキャッシュをセット。
	void SetAreaIdCache(uint32 AreaId) { AreaIdCache = AreaId; }

	// エリアＩＤキャッシュを取得.
	uint32 GetAreaIdCache() { return AreaIdCache; }

	
	// パケット受信delegate
	FOnRecvPacketDelegate OnRecvPacketDelegate;

private:

	// ゲームサーバへの接続.
	GameServerConnection *pConnection;

	// ステータスキャッシュ
	PlayerStatus StatusCache;

	// エリアＩＤキャッシュ
	uint32 AreaIdCache;


	// パケットを受信した。
	void OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream);
	
};

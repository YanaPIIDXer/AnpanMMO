// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ActiveGameMode.generated.h"

enum PacketID;
class MemoryStreamInterface;

/**
 * ゲーム中GameMode
 */
UCLASS()
class ANPANMMO_API AActiveGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	// コンストラクタ
	AActiveGameMode(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AActiveGameMode() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

protected:

private:

	// パケットを受信した。
	void OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream);
	

	

};

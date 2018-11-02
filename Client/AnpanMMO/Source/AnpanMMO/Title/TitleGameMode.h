// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TitleGameMode.generated.h"

enum PacketID;
class MemoryStreamInterface;

/**
 * タイトル画面GameMode
 */
UCLASS()
class ANPANMMO_API ATitleGameMode : public AGameMode
{

	GENERATED_BODY()
	
public:

	// コンストラクタ
	ATitleGameMode(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~ATitleGameMode() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

private:
	
	// パケットを受信した。
	void OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream);
	
};

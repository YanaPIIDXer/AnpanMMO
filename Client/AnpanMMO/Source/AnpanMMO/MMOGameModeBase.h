// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include <functional>
#include "MMOGameModeBase.generated.h"

enum PacketID;
class MemoryStreamInterface;
using namespace std::placeholders;

/**
 * GameMode基底クラス
 */
UCLASS()
class ANPANMMO_API AMMOGameModeBase : public AGameModeBase
{

	GENERATED_BODY()

private:		// 別名定義.

	typedef std::function<void(MemoryStreamInterface *)> PacketFunc;
	typedef TMap<PacketID, PacketFunc> FunctionMap;

public:

	// コンストラクタ
	AMMOGameModeBase(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AMMOGameModeBase() {}

	// 開始時の処理.
	virtual void BeginPlay() override;
	
protected:

	// パケット解析関数追加.
	void AddPacketFunction(PacketID ID, const PacketFunc &Func);

private:

	// パケット解析関数群.
	FunctionMap PacketFunctions;


	// パケットを受信した。
	void OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream);

};

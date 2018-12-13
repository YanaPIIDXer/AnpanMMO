// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include <functional>
#include <map>
#include "Packet/PacketID.h"
#include "MMOGameModeBase.generated.h"

class MemoryStreamInterface;
class ULayeredMenuWidgetBase;
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
	typedef std::map<uint8, PacketFunc> FunctionMap;

public:

	// コンストラクタ
	AMMOGameModeBase(const FObjectInitializer &ObjectInitializer);

	// デストラクタ
	virtual ~AMMOGameModeBase() {}

	// 開始時の処理.
	virtual void BeginPlay() override;

	// 現在のメニューを設定.
	void SetCurrentMenu(ULayeredMenuWidgetBase *pMenu) { pCurrentMenu = pMenu; }
	
protected:

	// パケット解析関数追加.
	void AddPacketFunction(uint8 ID, const PacketFunc &Func);

private:

	// パケット解析関数群.
	FunctionMap PacketFunctions;

	// 現在のメニュー
	TWeakObjectPtr<ULayeredMenuWidgetBase> pCurrentMenu;


	// パケットを受信した。
	void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream);

};

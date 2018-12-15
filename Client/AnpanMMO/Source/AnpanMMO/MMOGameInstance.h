// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Connection/GameServerConnection.h"
#include "Character/Player/PlayerStatus.h"
#include "Script/ScriptExecuter.h"
#include "FlexArray.h"
#include "MMOGameInstance.generated.h"

class PacketBase;
class SkillTreeNode;

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

	// 初期化時の処理.
	virtual void Init() override;

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
	void OnRecvStatus(uint32 Uuid, const FString &Name, u8 Job, uint32 Level, int32 MaxHp, int32 Atk, int32 Def, int32 Exp, u32 Gold);

	// スキルリストを受信した。
	void OnRecvSkillList(uint32 NormalAttack, uint32 Skill1, uint32 Skill2, uint32 Skill3, uint32 Skill4);

	// スキルツリーデータを受信した。
	void OnRecvSkillTreeData(const FlexArray<SkillTreeNode> &Nodes);

	// ステータスキャッシュ取得.
	const PlayerStatus &GetStatusCache() const { return StatusCache; }

	// エリアＩＤキャッシュをセット。
	void SetAreaIdCache(uint32 AreaId) { AreaIdCache = AreaId; }

	// エリアＩＤキャッシュを取得.
	uint32 GetAreaIdCache() { return AreaIdCache; }

	// スクリプト実行オブジェクトを取得.
	ScriptExecuter *GetScript() { return &Script; }

	
	// パケット受信delegate
	FOnRecvPacketDelegate OnRecvPacketDelegate;

private:

	// ゲームサーバへの接続.
	GameServerConnection *pConnection;

	// ステータスキャッシュ
	PlayerStatus StatusCache;

	// エリアＩＤキャッシュ
	uint32 AreaIdCache;

	// スクリプト実行.
	ScriptExecuter Script;


	// パケットを受信した。
	void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream);
	
};

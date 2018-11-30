// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/PartyMemberData.h"

class MemoryStreamInterface;
class AActiveGameMode;

/**
 * パーティ情報.
 */
class ANPANMMO_API PartyInformation
{

public:

	// コンストラクタ
	PartyInformation();

	// デストラクタ
	~PartyInformation() {}

	// GameModeをセット。
	void SetGameMode(AActiveGameMode *pInGameMode) { pGameMode = pInGameMode; }

	// 参加しているか？
	bool IsJoined() const { return (PartyId != 0); }

	// リーダーか？
	bool IsLeader() const { return bIsLeader; }

	// メンバリストを取得.
	TArray<PartyMemberData> GetMemberList() const;

	// 作成結果を受信した。
	void OnRecvCreateResult(MemoryStreamInterface *pStream);

	// 解散結果を受信した。
	void OnRecvDissolutionResult(MemoryStreamInterface *pStream);

	// 離脱結果を受信した。
	void OnRecvExitResult(MemoryStreamInterface *pStream);

	// 参加を受信した。
	void OnRecvJoin(MemoryStreamInterface *pStream);

	// メンバ加入を受信した。
	void OnRecvJoinMember(MemoryStreamInterface *pStream);

	// メンバ離脱を受信した。
	void OnRecvExitMember(MemoryStreamInterface *pStream);

	// 解散を受信した。
	void OnRecvDissolution(MemoryStreamInterface *pStream);

private:

	// パーティＩＤ
	uint32 PartyId;

	// リーダーか？
	bool bIsLeader;

	// GameMode
	TWeakObjectPtr<AActiveGameMode> pGameMode;

	// メンバリスト
	TMap<uint32, PartyMemberData> MemberList;

};

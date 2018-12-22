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
	bool OnRecvCreateResult(MemoryStreamInterface *pStream);

	// 解散結果を受信した。
	bool OnRecvDissolutionResult(MemoryStreamInterface *pStream);

	// 離脱結果を受信した。
	bool OnRecvExitResult(MemoryStreamInterface *pStream);

	// 参加を受信した。
	bool OnRecvJoin(MemoryStreamInterface *pStream);

	// メンバ加入を受信した。
	bool OnRecvJoinMember(MemoryStreamInterface *pStream);

	// メンバ離脱を受信した。
	bool OnRecvExitMember(MemoryStreamInterface *pStream);

	// メンバキックを受信した。
	bool OnRecvKickMember(MemoryStreamInterface *pStream);

	// 解散を受信した。
	bool OnRecvDissolution(MemoryStreamInterface *pStream);

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

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

	// 作成結果を受信した。
	void OnRecvCreateResult(MemoryStreamInterface *pStream);

	// 解散結果を受信した。
	void OnRecvDissolutionResult(MemoryStreamInterface *pStream);

	// メンバリストを受信した。
	void OnRecvMemberList(MemoryStreamInterface *pStream);

	// メンバ加入を受信した。
	void OnRecvJoinMember(MemoryStreamInterface *pStream);

private:

	// パーティＩＤ
	uint32 PartyId;

	// GameMode
	TWeakObjectPtr<AActiveGameMode> pGameMode;

	// メンバリスト
	TArray<PartyMemberData> MemberList;

};

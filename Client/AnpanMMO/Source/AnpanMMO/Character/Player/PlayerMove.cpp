// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerMove.h"
#include "GameCharacter.h"
#include "MMOGameInstance.h"
#include "Packet/PacketMovePlayer.h"

const float PlayerMove::SendInterval = 5.0f;

// コンストラクタ
PlayerMove::PlayerMove()
	: pCharacter(nullptr)
	, pInst(nullptr)
	, PrevPos(FVector::ZeroVector)
	, SendTimer(SendInterval)
{
}

// 初期化.
void PlayerMove::Initialize(AGameCharacter *pInCharacter, UMMOGameInstance *pInInst)
{
	pCharacter = pInCharacter;
	pInst = pInInst;
	PrevPos = pCharacter->GetActorLocation();
}

// 毎フレームの処理.
void PlayerMove::Poll(float DeltaTime)
{
	SendTimer -= DeltaTime;
	if (SendTimer <= 0.0f)
	{
		SendTimer += SendInterval;

		FVector Pos = pCharacter->GetActorLocation();
		if (PrevPos == Pos) { return; }

		PacketMovePlayer Packet(pCharacter->GetStatus().GetUuid(), Pos.X, Pos.Y, pCharacter->GetActorRotation().Yaw);
		pInst->SendPacket(&Packet);
		
		PrevPos = Pos;
	}
}

// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PlayerMove.h"
#include "GameCharacter.h"
#include "MMOGameInstance.h"
#include "Packet/PacketMovePlayer.h"

const float PlayerMove::SendInterval = 2.0f;

// コンストラクタ
PlayerMove::PlayerMove()
	: pCharacter(nullptr)
	, pInst(nullptr)
	, PrevPos(FVector::ZeroVector)
	, SendTimer(SendInterval)
	, CharacterHalfHeight(0.0f)
{
}

// 初期化.
void PlayerMove::Initialize(AGameCharacter *pInCharacter, UMMOGameInstance *pInInst)
{
	pCharacter = pInCharacter;
	pInst = pInInst;
	PrevPos = pCharacter->GetActorLocation();
	CharacterHalfHeight = pCharacter->GetHalfHeight();
}

// 毎フレームの処理.
void PlayerMove::Poll(float DeltaTime)
{
	SendTimer -= DeltaTime;
	if (SendTimer <= 0.0f)
	{
		SendTimer += SendInterval;

		FVector Pos = pCharacter->GetActorLocation();
		
		// GetActorLocationで取得できるのはキャラの中心の座標なので
		// キャラの高さの半分だけズラす。
		// ※キャラの足元の座標を送る。
		Pos.Z -= CharacterHalfHeight;

		if (PrevPos == Pos) { return; }

		PacketMovePlayer Packet(pCharacter->GetStatus().GetUuid(), Pos.X, Pos.Y, Pos.Z, pCharacter->GetActorRotation().Yaw);
		pInst->SendPacket(&Packet);
		
		PrevPos = Pos;
	}
}

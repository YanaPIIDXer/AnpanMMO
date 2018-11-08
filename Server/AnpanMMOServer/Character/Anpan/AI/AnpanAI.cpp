#include "stdafx.h"
#include "AnpanAI.h"
#include "Character/Anpan/Anpan.h"
#include "State/AnpanAIStateBase.h"
#include "State/AnpanAIStateNonActive.h"

// コンストラクタ
AnpanAI::AnpanAI(Anpan *pInParent)
	: pParent(pInParent)
	, pMovePacketData(NULL)
	, pRotatePacketData(NULL)
{
	ChangeState(new AnpanAIStateNonActive(pInParent));
}

// デストラクタ
AnpanAI::~AnpanAI()
{
	delete pState;
	pState = NULL;

	delete pMovePacketData;
	pMovePacketData = NULL;

	delete pRotatePacketData;
	pRotatePacketData = NULL;
}

// 毎フレームの処理.
void AnpanAI::Poll(int DeltaTime)
{
	pState->Poll(DeltaTime);
}

// ステート切り替え.
void AnpanAI::ChangeState(AnpanAIStateBase *pNewState)
{
	delete pState;
	pState = pNewState;
	pState->SetAI(this);
}

// 移動パケットデータの生成.
void AnpanAI::CreateMovePacketData(const Vector2D &Position, int Time)
{
	pMovePacketData = new AnpanMovePacketData(pParent->GetUuid(), Position, Time);
}

// 移動パケットデータの取得.
AnpanMovePacketData *AnpanAI::SweepMovePacketData()
{
	AnpanMovePacketData *pData = pMovePacketData;
	pMovePacketData = NULL;
	return pData;
}

// 回転パケットデータの生成.
void AnpanAI::CreateRotatePacketData(const Rotation &Rot, int Time)
{
	pRotatePacketData = new AnpanRotatePacketData(pParent->GetUuid(), Rot, Time);
}

// 回転パケットデータの取得.
AnpanRotatePacketData *AnpanAI::SweepRotatePacketData()
{
	AnpanRotatePacketData *pData = pRotatePacketData;
	pRotatePacketData = NULL;
	return pData;
}

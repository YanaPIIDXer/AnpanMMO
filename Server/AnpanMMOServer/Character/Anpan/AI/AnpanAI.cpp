#include "stdafx.h"
#include "AnpanAI.h"
#include "Character/Anpan/Anpan.h"
#include "State/AnpanAIStateBase.h"
#include "State/AnpanAIStateNonActive.h"

// コンストラクタ
AnpanAI::AnpanAI(Anpan *pInParent)
	: pParent(pInParent)
	, bIsNeedSendStopPacket(false)
	, pPrevState(NULL)
{
	pMovePacketData.reset();
	pRotatePacketData.reset();
	ChangeState(new AnpanAIStateNonActive(pInParent));
}

// デストラクタ
AnpanAI::~AnpanAI()
{
	delete pState;
	pState = NULL;

	delete pPrevState;
	pPrevState = NULL;

	pMovePacketData.reset();
	pRotatePacketData.reset();
}

// 毎フレームの処理.
void AnpanAI::Poll(int DeltaTime)
{
	if (pPrevState != NULL)
	{
		delete pPrevState;
		pPrevState = NULL;
	}
	pState->Poll(DeltaTime);
	HateManager.Poll();
}

// ステート切り替え.
void AnpanAI::ChangeState(AnpanAIStateBase *pNewState)
{
	pPrevState = pState;
	pState = pNewState;
	pState->SetAI(this);
}

// 移動パケットデータの生成.
void AnpanAI::CreateMovePacketData(const Vector2D &Position, int Time)
{
	pMovePacketData = shared_ptr<AnpanMovePacketData>(new AnpanMovePacketData(pParent->GetUuid(), Position, Time));
}

// 移動パケットデータの取得.
shared_ptr<AnpanMovePacketData> AnpanAI::SweepMovePacketData()
{
	shared_ptr<AnpanMovePacketData> pData = pMovePacketData;
	pMovePacketData.reset();
	return pData;
}

// 回転パケットデータの生成.
void AnpanAI::CreateRotatePacketData(const Rotation &Rot, int Time)
{
	pRotatePacketData = shared_ptr<AnpanRotatePacketData>(new AnpanRotatePacketData(pParent->GetUuid(), Rot, Time));
}

// 回転パケットデータの取得.
shared_ptr<AnpanRotatePacketData> AnpanAI::SweepRotatePacketData()
{
	shared_ptr<AnpanRotatePacketData> pData = pRotatePacketData;
	pRotatePacketData.reset();
	return pData;
}

// 停止パケットの送信を取得.
bool AnpanAI::SweepSendStopPacketFlag()
{
	bool bSend = bIsNeedSendStopPacket;
	bIsNeedSendStopPacket = false;
	return bSend;
}

// ダメージを受けた。
void AnpanAI::OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue)
{
	HateManager.Add(pAttacker, DamageValue);
	pState->OnDamaged();
}

#include "stdafx.h"
#include "AnpanAIStateNonActive.h"
#include "Math/Random.h"
#include "Character/Anpan/Anpan.h"
#include "AnpanAIStateActive.h"

// コンストラクタ
AnpanAIStateNonActive::AnpanAIStateNonActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
	, CurrentState(None)
	, StateTime(0)
{
}

// ダメージを受けた。
void AnpanAIStateNonActive::OnDamaged()
{
	if (StateTime > 0)
	{
		// 何かしら行動しているので停止.
		Stop();
		StateTime = 0;
	}

	// アクティブ状態へ。
	GetAI()->ChangeState(new AnpanAIStateActive(GetParent()));
}


// 更新処理.
void AnpanAIStateNonActive::Update(int DeltaTime)
{
	std::cout << "AI Update DeltaTime;" << DeltaTime << std::endl;
	if (CurrentState == None)
	{
		// 内部ステートの初期化.
		StateTime = Random::Range<int>(1000, 5000);
		CurrentState = Stopping;
	}

	StateTime -= DeltaTime;
	if (StateTime < 0)
	{
		StateTime = 0;
	}

	switch (CurrentState)
	{
		case Stopping:

			UpdateStopping();
			break;

		case Rotating:

			UpdateRotating();
			break;

		case Moving:

			UpdateMoving();
			break;

	}
}


// 停止状態の更新.
void AnpanAIStateNonActive::UpdateStopping()
{
	if (StateTime <= 0)
	{
		// 回転.
		float RotateValue = Random::Range<float>(0.0f, 360.0f);
		StateTime = Random::Range<int>(1000, 3000);
		SetRotate(RotateValue, StateTime);
		CurrentState = Rotating;
	}
}

// 回転状態の更新.
void AnpanAIStateNonActive::UpdateRotating()
{
	if (StateTime <= 0)
	{
		// 移動.
		Vector2D Vec = GetParent()->GetCenterVec();
		Vec *= Random::Range<float>(500.0f, 1000.0f);
		StateTime = Random::Range<int>(3000, 5000);
		SetMove(Vec, StateTime);
		CurrentState = Moving;
	}
}

// 移動状態の更新.
void AnpanAIStateNonActive::UpdateMoving()
{
	if (StateTime <= 0)
	{
		CurrentState = Stopping;
		StateTime = Random::Range<int>(1000, 5000);
	}
}

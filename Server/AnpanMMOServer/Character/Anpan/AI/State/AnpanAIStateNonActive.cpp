#include "stdafx.h"
#include "AnpanAIStateNonActive.h"
#include "Math/Random.h"
#include "Character/Anpan/Anpan.h"

// コンストラクタ
AnpanAIStateNonActive::AnpanAIStateNonActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
	, CurrentState(None)
	, StateTime(0)
{
}


// 更新処理.
void AnpanAIStateNonActive::Update(int DeltaTime)
{
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
		Rotation Rot(Random::Range<float>(0.0f, 360.0f));
		StateTime = Random::Range<int>(1000, 3000);
		SetRotate(Rot, StateTime);
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
		Vec *= Random::Range<float>(-1000.0f, 1000.0f);
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

/**
 * @file AnpanAIStateNonActive.cpp
 * @brief �A���p���`�h�X�e�[�g�F�m���A�N�e�B�u���
 * @author YanaP
 */
#include "stdafx.h"
#include "AnpanAIStateNonActive.h"
#include "Math/Random.h"
#include "Character/Anpan/Anpan.h"
#include "AnpanAIStateActive.h"

// �R���X�g���N�^
AnpanAIStateNonActive::AnpanAIStateNonActive(Anpan *pInParent)
	: AnpanAIStateBase(pInParent)
	, CurrentState(None)
	, StateTime(0)
{
}


// �X�V����.
void AnpanAIStateNonActive::Update(int DeltaTime)
{
	if (CurrentState == None)
	{
		// �����X�e�[�g�̏�����.
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

		default:
			break;
	}
}


// ��~��Ԃ̍X�V.
void AnpanAIStateNonActive::UpdateStopping()
{
	if (StateTime <= 0)
	{
		// ��].
		float RotateValue = Random::Range<float>(0.0f, 360.0f);
		StateTime = Random::Range<int>(1000, 3000);
		SetRotate(RotateValue, StateTime);
		CurrentState = Rotating;
	}
}

// ��]��Ԃ̍X�V.
void AnpanAIStateNonActive::UpdateRotating()
{
	if (StateTime <= 0)
	{
		// �ړ�.
		Vector3D Vec = GetParent()->GetCenterVec();
		Vec *= Random::Range<float>(500.0f, 1000.0f);
		StateTime = Random::Range<int>(3000, 5000);
		SetMove(Vec, StateTime);
		CurrentState = Moving;
	}
}

// �ړ���Ԃ̍X�V.
void AnpanAIStateNonActive::UpdateMoving()
{
	if (StateTime <= 0)
	{
		CurrentState = Stopping;
		StateTime = Random::Range<int>(1000, 5000);
	}
}

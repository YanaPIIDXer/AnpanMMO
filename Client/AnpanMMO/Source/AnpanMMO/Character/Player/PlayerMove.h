// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class AGameCharacter;
class UMMOGameInstance;

/**
 * �v���C���[�ړ��p�P�b�g�����N���X
 */
class ANPANMMO_API PlayerMove
{

public:

	// �R���X�g���N�^
	PlayerMove();

	// �f�X�g���N�^
	~PlayerMove() {}

	// ������.
	void Initialize(AGameCharacter *pInCharacter, UMMOGameInstance *pInInst);

	// ���t���[���̏���.
	void Poll(float DeltaTime);

private:

	// ���M�C���^�[�o��
	static const float SendInterval;

	// �v���C���[�L����
	TWeakObjectPtr<AGameCharacter> pCharacter;

	// GameInstance
	TWeakObjectPtr<UMMOGameInstance> pInst;

	// �ȑO�̍��W.
	FVector PrevPos;

	// ���M�^�C�}�[
	float SendTimer;

	// �L�����̍����̔���.
	float CharacterHalfHeight;

};

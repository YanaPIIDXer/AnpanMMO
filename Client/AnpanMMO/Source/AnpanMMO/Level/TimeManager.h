// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class ASkyControl;
class MemoryStreamInterface;

/**
 * ���ԊǗ�.
 */
class ANPANMMO_API TimeManager
{

public:

	// �R���X�g���N�^
	TimeManager();

	// �f�X�g���N�^
	~TimeManager() {}

	// �V�����Z�b�g�B
	void SetSkyControl(ASkyControl *pInSky);

	// �J�n���̎��Ԃ��󂯎�����B
	void OnRecvTime(MemoryStreamInterface *pStream);

	// ���ԕϓ����󂯎�����B
	void OnRecvTimeChange(MemoryStreamInterface *pStream);

private:

	// �V��.
	TWeakObjectPtr<ASkyControl> pSky;

	// ���݂̃}�X�^�h�c
	uint32 CurrentMasterId;

};

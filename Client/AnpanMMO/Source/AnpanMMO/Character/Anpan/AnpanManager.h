// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class AAnpan;

/**
 * �A���p���Ǘ�.
 */
class ANPANMMO_API AnpanManager
{

private:		// �ʖ���`.

	typedef TWeakObjectPtr<AAnpan> AnpanPtr;

public:

	// �R���X�g���N�^
	AnpanManager();

	// �f�X�g���N�^
	~AnpanManager() {}

private:

	// �A���p���}�b�v
	TMap<uint32, AnpanPtr> AnpanMap;

};

// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * �萔��`.
 */
class ANPANMMO_API Config
{

public:

	// �T�[�o�z�X�g
	static const FString ServerHost;

	// �T�[�o�|�[�g
	static const int ServerPort;

	// ID�t�@�C���̃t�@�C���p�X�擾.
	static FString GetIdFilePath();

};

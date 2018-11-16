// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class AWarpPoint;

/**
 * ���[�v�|�C���g�Ǘ��N���X
 */
class ANPANMMO_API WarpPointManager
{

private:		// �ʖ���`.

	typedef TWeakObjectPtr<AWarpPoint> WarpPointPtr;

public:

	// �R���X�g���N�^
	WarpPointManager();

	// �f�X�g���N�^
	~WarpPointManager() {}

private:

	// ���[�v�|�C���g���X�g
	TArray<WarpPointPtr> WarpPoints;

};

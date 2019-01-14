// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

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

	// �}�X�^�t�q�k
	static const FString MasterURL;

	// �}�X�^�f�B���N�g�����擾.
	static FString GetMasterDirectory();

	// �X�N���v�g�t�q�k
	static const FString ScriptURL;

	// �X�N���v�g�f�B���N�g�����擾.
	static FString GetScriptDirectory();

private:

	// DLC��URL
	static const FString DLCURL;

public:

	// DLC��URL���擾
	static FString GetDLCURL();

	// DLC�f�B���N�g�����擾.
	static FString GetDLCDirectory();

};

// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScriptModule/ScriptExecuterBase.h"

/**
 * �X�N���v�g����N���X
 */
class ANPANMMO_API ScriptExecuter : public ScriptExecuterBase
{

public:

	// �R���X�g���N�^
	ScriptExecuter();

	// �f�X�g���N�^
	virtual ~ScriptExecuter() {}

	// �X�N���v�g�����s.
	void RunScript(const FString &FileName);

	// ���b�Z�[�W��\��.
	virtual void ShowMessage_Impl(const std::string &Message);

	// �I�������v�b�V��
	virtual void PushSelection_Impl(const std::string &Message);

	// �I������\��.
	virtual void ShowSelection_Impl();

	// �t���O���Z�b�g.
	virtual void SetFlag(const char *pFlagName);

	// �t���O���擾.
	virtual bool GetFlag(const char *pFlagName);

	// ���s�G���[
	virtual void OnExecuteError(const std::string &ErrorMessage);

private:

};
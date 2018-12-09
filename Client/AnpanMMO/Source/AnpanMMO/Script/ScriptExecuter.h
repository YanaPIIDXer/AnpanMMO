// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScriptExecuterBase.h"

class AActiveGameMode;

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

	// GameMode��ݒ�.
	void SetGameMode(AActiveGameMode *pInGameMode) { pGameMode = pInGameMode; }

	// �X�N���v�g�����s.
	void RunScript(const FString &FileName);

	// ���b�Z�[�W��\��.
	virtual void ShowMessage_Impl(const std::string &Message) override;

	// �I�������v�b�V��
	virtual void PushSelection_Impl(const std::string &Message) override;

	// �I������\��.
	virtual void ShowSelection_Impl() override;

	// �t���O���Z�b�g.
	virtual void SetFlag(int Flag) override;

	// �t���O���擾.
	virtual bool GetFlag(int Flag) override;

protected:

	// ���s�G���[
	virtual void OnExecuteError(const std::string &ErrorMessage) override;

	// �I�������B
	virtual void OnFinished() override;

	// �f�o�b�O�p���b�Z�[�W��\��.
	virtual void ShowDebugMessage(const std::string &Message) override;

	// �T�[�o���[�h���H
	virtual bool IsServer() const override { return false; }

private:

	// GameMode
	TWeakObjectPtr<AActiveGameMode> pGameMode;

};

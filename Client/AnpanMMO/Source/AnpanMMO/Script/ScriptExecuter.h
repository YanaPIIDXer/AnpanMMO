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

	// �N�G�X�g���i�s�����H
	virtual bool IsQuestActive(u32 QuestId) override;

	// �N�G�X�g�i�s.
	// ���N���C�A���g���͉������Ȃ��B
	virtual void ProgressQuest(u32 QuestId) override {}

	// �N�G�X�g�̃X�e�[�W�ԍ����擾.
	virtual u32 GetQuestStageNo(u32 QuestId) override;

	// �A�C�e���̌����擾.
	virtual u32 GetItemCount(u32 ItemId) override;

	// �A�C�e������.
	// ���N���C�A���g���͉������Ȃ��B
	virtual void ConsumeItem(u32 ItemId, u32 Count) override {}

	// �N�G�X�g��.
	// ���N���C�A���g���͉������Ȃ��B
	virtual void AcceptQuest(u32 QuestId) override {}

	// �N�G�X�g���N���A���Ă��邩�H
	virtual bool IsQuestClear(u32 QuestId) override;

	// �r�b�g�t�B�[���h����t���O�ɕϊ�.
	void ConvertFlagFromBitFields(uint32 BitField1, uint32 BitField2, uint32 BitField3);

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

	// �t���O�}�b�v
	TMap<int32, bool> FlagMap;


	// ������.
	char *Composite(const uint8 *pData, int32 DataSize);

};

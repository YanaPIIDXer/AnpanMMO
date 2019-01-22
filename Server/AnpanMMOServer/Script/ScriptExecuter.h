#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "ScriptExecuterBase.h"

class Client;

/**
 * �X�N���v�g���s�N���X
 */
class ScriptExecuter : public ScriptExecuterBase
{

public:

	// �R���X�g���N�^
	ScriptExecuter();

	// �f�X�g���N�^
	virtual ~ScriptExecuter() {}

	// �N���C�A���g���Z�b�g�B
	void SetClient(Client *pInClient) { pClient = pInClient; }

	u32 GetCurrentShopId() const { return CurrentShopId; }

	// �ǂݍ���Ŏ��s.
	void LoadAndRun(const std::string &FileName);

	// ���b�Z�[�W��\��.
	virtual void ShowMessage_Impl(const std::string &Message) {}

	// �I�������v�b�V�����ꂽ�B
	virtual void PushSelection_Impl(const std::string &Message) {}

	// �I�����\��.
	virtual void ShowSelection_Impl() {}

	// �t���O���Z�b�g
	virtual void SetFlag(int Flag);

	// �t���O���擾.
	virtual bool GetFlag(int Flag);

	// �N�G�X�g���i�s�����H
	virtual bool IsQuestActive(u32 QuestId);

	// �N�G�X�g�i�s.
	virtual void ProgressQuest(u32 QuestId);

	// �N�G�X�g�̃X�e�[�W�ԍ����擾.
	virtual u32 GetQuestStageNo(u32 QuestId);

	// �A�C�e���̌����擾.
	virtual u32 GetItemCount(u32 ItemId);

	// �A�C�e������.
	virtual void ConsumeItem(u32 ItemId, u32 Count);

	// �N�G�X�g��.
	virtual void AcceptQuest(u32 QuestId);

	// �N�G�X�g���N���A���Ă��邩�H
	virtual bool IsQuestClear(u32 QuestId);

	// �V���b�v��ʕ\��
	virtual void ShowShop_Impl(u32 ShopId) { CurrentShopId = ShopId; }

protected:

	// ���s�G���[
	virtual void OnExecuteError(const std::string &ErrorMessage);

	// �������I�������B
	virtual void OnFinished();

	// �f�o�b�O���b�Z�[�W��\��.
	virtual void ShowDebugMessage(const std::string &Message);

	// �T�[�o���[�h���H
	virtual bool IsServer() const { return true; }

private:

	// �N���C�A���g
	Client *pClient;

	// ���݂̃V���b�v�h�c
	u32 CurrentShopId;

};

#endif		// #ifndef __SCRIPTEXECUTER_H_

// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include "Character/Player/PlayerManager.h"
#include "Character/Anpan/AnpanManager.h"
#include "WarpPoint/WarpPointManager.h"
#include "Party/PartyInformation.h"
#include "Notice/NoticeManager.h"
#include "Ping/PingManager.h"
#include "Level/TimeManager.h"
#include "Character/NPC/NPCManager.h"
#include "ActiveGameMode.generated.h"

class UMainHUD;
class UGameMenuWidget;
class ULevelManager;
class AOtherPlayerCharacter;
class UScriptWidgetRoot;

/**
 * �Q�[����GameMode
 */
UCLASS()
class ANPANMMO_API AActiveGameMode : public AMMOGameModeBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	AActiveGameMode(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AActiveGameMode() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

	// �v���C���[�L�����ǉ�.
	void AddPlayerCharacter(uint32 Uuid, APlayerCharacterBase *pPlayer);

	// ���C��HUD�擾.
	UFUNCTION(BlueprintPure, Category = "HUD")
	UMainHUD *GetMainHUD() const { return pMainHUD; }

	// �}�b�v���[�h�J�n.
	void StartLevelLoad(uint32 AreaId);

	// ���x�����[�h�����������B
	void OnLevelLoadFinished();

	// ���C��HUD��\�����邩�ǂ�����ݒ�.
	void SetHiddenMainHUD(bool bHidden);

	// �p�[�e�B���擾.
	const PartyInformation &GetPartyInfo() const { return PartyInfo; }

	// �ʒm���X�g���擾.
	TArray<NoticeInformation> GetNoticeList() const { return NoticeMgr.GetNoticeList(); }

	// �ʒm������.
	void RemoveNotice(uint32 Uuid) { NoticeMgr.RemoveNotice(Uuid); }

	// �V�����Z�b�g�B
	void RegisterSkyControl(ASkyControl *pSky);

	// �X�N���v�g�̎��s�J�n.
	void StartScript(const FString &ScriptFileName);

	// �X�N���v�g�̃��b�Z�[�W�\��.
	void ShowScriptMessage(const FString &Message);

	// �X�N���v�g�̑I������ǉ�.
	void AddScriptSelection(const FString &Item);

	// �X�N���v�g�̑I������\��.
	void ShowScriptSelection();

	// �V���b�v��\��.
	void ShowShop(uint32 ShopId);

	// �X�N���v�g�I��.
	void FinishScript();

	// �L�������猩���O���̃^�[�Q�b�g���擾.
	AAnpan *FindCenterTarget(float Distance);

protected:

private:

	// �v���C���[�Ǘ�.
	PlayerManager PlayerMgr;

	// �A���p���Ǘ�.
	AnpanManager AnpanMgr;

	// ���[�v�|�C���g�}�l�[�W��
	WarpPointManager WarpPointMgr;

	// Ping�Ǘ�.
	PingManager PingMgr;

	// ���ԊǗ�.
	TimeManager TimeMgr;

	// NPC�Ǘ�.
	NPCManager NPCMgr;

	// MainHUD
	UPROPERTY()
	UMainHUD *pMainHUD;

	// ���x���Ǘ�.
	UPROPERTY()
	ULevelManager *pLevelManager;

	// �X�N���v�gWidget
	UPROPERTY()
	UScriptWidgetRoot *pScriptWidget;

	// �p�[�e�B���.
	PartyInformation PartyInfo;

	// �ʒm�Ǘ�.
	NoticeManager NoticeMgr;

	// MainHUD���������������H
	bool bInitializedMainHUD;


	// �L�����N�^�^�C�v����L�����N�^���擾.
	ACharacterBase *GetCharacterFromType(uint8 CharacterType, uint32 Uuid);

	// �G���A�ړ�����M�����B
	bool OnRecvAreaMove(MemoryStreamInterface *pStream);

	// �_���[�W����M�����B
	bool OnRecvDamage(MemoryStreamInterface *pStream);

	// �񕜂���M�����B
	bool OnRecvHeal(MemoryStreamInterface *pStream);

	// �o���l����M�����B
	bool OnRecvAddExp(MemoryStreamInterface *pStream);

	// ���x���A�b�v����M�����B
	bool OnRecvLevelUp(MemoryStreamInterface *pStream);

	// �G���A�ړ����ʂ���M�����B
	bool OnRecvAreaMoveResponse(MemoryStreamInterface *pStream);

	// ���X�|������M�����B
	bool OnRecvRespawn(MemoryStreamInterface *pStream);

	// �X�L���L���X�g����M�����B
	bool OnRecvSkillCast(MemoryStreamInterface *pStream);

	// �X�L���L���X�g��������M�����B
	bool OnRecvSkillCastFinish(MemoryStreamInterface *pStream);

	// �X�L����������M�����B
	bool OnRecvSkillActivate(MemoryStreamInterface *pStream);

	// �X�L���������s����M�����B
	bool OnRecvSkillUseFailed(MemoryStreamInterface *pStream);

	// �X�L���̃��L���X�g��������M�����B
	bool OnRecvSkillRecast(MemoryStreamInterface *pStream);

	// �`���b�g����M�����B
	bool OnRecvChat(MemoryStreamInterface *pStream);

	// �L�b�N���ʂ���M�����B
	bool OnRecvPartyKickResult(MemoryStreamInterface *pStream);

	// �p�[�e�B���U���ʂ���M�����B
	bool OnRecvPartyInviteResult(MemoryStreamInterface *pStream);

	// �C���X�^���X�}�b�v�`�P�b�g���s����M�����B
	bool OnRecvInstanceAreaTicketPublish(MemoryStreamInterface *pStream);

	// �C���X�^���X�}�b�v�`�P�b�g�j������M�����B
	bool OnRecvInstanceAreaTicketDiscard(MemoryStreamInterface *pStream);

	// �C���X�^���X�G���A�E�o�|�C���g��������M�����B
	bool OnRecvSpawnInstanceAreaExitPoint(MemoryStreamInterface *pStream);

	// �S�[���h�ω�����M�����B
	bool OnRecvChangeGold(MemoryStreamInterface *pStream);

	// �X�L���c���[�J�����ʂ���M�����B
	bool OnRecvSkillTreeOpenResult(MemoryStreamInterface *pStream);

	// �X�L�����X�g�ۑ����X�|���X����M�����B
	bool OnRecvSaveSkillListResponse(MemoryStreamInterface *pStream);

	// �A�C�e���ǉ�����M�����B
	bool OnRecvAddItem(MemoryStreamInterface *pStream);

	// �A�C�e�����ł���M�����B
	bool OnRecvSubtractItem(MemoryStreamInterface *pStream);

	// �A�C�e���V���[�g�J�b�g�ۑ����ʂ���M�����B
	bool OnRecvSaveItemShortcutResult(MemoryStreamInterface *pStream);

	// �N�G�X�g�󒍂���M�����B
	bool OnRecvAcceptQuest(MemoryStreamInterface *pStream);

	// �N�G�X�g�i�s����M�����B
	bool OnRecvProgressQuest(MemoryStreamInterface *pStream);

	// �N�G�X�g�ł̃A���p���E�Q����M�����B
	bool OnRecvQuestKilledAnpan(MemoryStreamInterface *pStream);

	// �N�G�X�g�N���A����M�����B
	bool OnRecvClearQuest(MemoryStreamInterface *pStream);

	// �N�G�X�g�j�����X�|���X����M�����B
	bool OnRecvRetireQuestResponse(MemoryStreamInterface *pStream);

	// �����ύX���ʂ���M�����B
	bool OnRecvEquipChangeResult(MemoryStreamInterface *pStream);

	// �o�t�ǉ�����M�����B
	bool OnRecvAddBuff(MemoryStreamInterface *pStream);

	// �o�t��������M�����B
	bool OnRecvRemoveBuff(MemoryStreamInterface *pStream);
	
};

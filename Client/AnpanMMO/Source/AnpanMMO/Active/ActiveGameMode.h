// Copyright 2018 YanaPIIDXer All Rights Reserved.

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
	void OnRecvAreaMove(MemoryStreamInterface *pStream);

	// �_���[�W����M�����B
	void OnRecvDamage(MemoryStreamInterface *pStream);

	// �񕜂���M�����B
	void OnRecvHeal(MemoryStreamInterface *pStream);

	// �o���l����M�����B
	void OnRecvAddExp(MemoryStreamInterface *pStream);

	// ���x���A�b�v����M�����B
	void OnRecvLevelUp(MemoryStreamInterface *pStream);

	// �G���A�ړ����ʂ���M�����B
	void OnRecvAreaMoveResponse(MemoryStreamInterface *pStream);

	// ���X�|������M�����B
	void OnRecvRespawn(MemoryStreamInterface *pStream);

	// �X�L���L���X�g����M�����B
	void OnRecvSkillCast(MemoryStreamInterface *pStream);

	// �X�L���L���X�g��������M�����B
	void OnRecvSkillCastFinish(MemoryStreamInterface *pStream);

	// �X�L����������M�����B
	void OnRecvSkillActivate(MemoryStreamInterface *pStream);

	// �X�L���������s����M�����B
	void OnRecvSkillUseFailed(MemoryStreamInterface *pStream);

	// �X�L���̃��L���X�g��������M�����B
	void OnRecvSkillRecast(MemoryStreamInterface *pStream);

	// �`���b�g����M�����B
	void OnRecvChat(MemoryStreamInterface *pStream);

	// �L�b�N���ʂ���M�����B
	void OnRecvPartyKickResult(MemoryStreamInterface *pStream);

	// �p�[�e�B���U���ʂ���M�����B
	void OnRecvPartyInviteResult(MemoryStreamInterface *pStream);

	// �C���X�^���X�}�b�v�`�P�b�g���s����M�����B
	void OnRecvInstanceAreaTicketPublish(MemoryStreamInterface *pStream);

	// �C���X�^���X�}�b�v�`�P�b�g�j������M�����B
	void OnRecvInstanceAreaTicketDiscard(MemoryStreamInterface *pStream);

	// �C���X�^���X�G���A�E�o�|�C���g��������M�����B
	void OnRecvSpawnInstanceAreaExitPoint(MemoryStreamInterface *pStream);

	// �S�[���h�ω�����M�����B
	void OnRecvChangeGold(MemoryStreamInterface *pStream);

	// �X�L���c���[�J�����ʂ���M�����B
	void OnRecvSkillTreeOpenResult(MemoryStreamInterface *pStream);

	// �X�L�����X�g�ۑ����X�|���X����M�����B
	void OnRecvSaveSkillListResponse(MemoryStreamInterface *pStream);

	// �A�C�e���ǉ�����M�����B
	void OnRecvAddItem(MemoryStreamInterface *pStream);

	// �A�C�e�����ł���M�����B
	void OnRecvSubtractItem(MemoryStreamInterface *pStream);

};

// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include "Character/Player/PlayerManager.h"
#include "Character/Anpan/AnpanManager.h"
#include "WarpPoint/WarpPointManager.h"
#include "Party/PartyInformation.h"
#include "Notice/NoticeManager.h"
#include "ActiveGameMode.generated.h"

class UMainHUD;
class UGameMenuWidget;
class UOtherPlayerPopupMenu;
class ULevelManager;
class AOtherPlayerCharacter;

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

	// ���l�̃|�b�v�A�b�v���j���[��\��.
	void ShowOtherPlayerPopupMenu(AOtherPlayerCharacter *pCharacter);

	// ���l�̃|�b�v�A�b�v���j���[������.
	void EraseOtherPlayerPopupMenu();

	// �p�[�e�B���擾.
	const PartyInformation &GetPartyInfo() const { return PartyInfo; }

	// �ʒm���X�g���擾.
	TArray<NoticeInformation> GetNoticeList() const { return NoticeMgr.GetNoticeList(); }

	// �ʒm������.
	void RemoveNotice(uint32 Uuid) { NoticeMgr.RemoveNotice(Uuid); }

protected:

private:

	// �v���C���[�Ǘ�.
	PlayerManager PlayerMgr;

	// �A���p���Ǘ�.
	AnpanManager AnpanMgr;

	// ���[�v�|�C���g�}�l�[�W��
	WarpPointManager WarpPointMgr;

	// MainHUD
	UPROPERTY()
	UMainHUD *pMainHUD;

	// ���l�̃|�b�v�A�b�v���j���[
	UPROPERTY()
	UOtherPlayerPopupMenu *pOtherPlayerMenu;

	// ���x���Ǘ�.
	UPROPERTY()
	ULevelManager *pLevelManager;

	// �p�[�e�B���.
	PartyInformation PartyInfo;

	// �ʒm�Ǘ�.
	NoticeManager NoticeMgr;

	// MainHUD���������������H
	bool bInitializedMainHUD;


	// �G���A�ړ�����M�����B
	void OnRecvAreaMove(MemoryStreamInterface *pStream);

	// �_���[�W����M�����B
	void OnRecvDamage(MemoryStreamInterface *pStream);

	// �o���l����M�����B
	void OnRecvAddExp(MemoryStreamInterface *pStream);

	// ���x���A�b�v����M�����B
	void OnRecvLevelUp(MemoryStreamInterface *pStream);

	// �G���A�ړ����ʂ���M�����B
	void OnRecvAreaMoveResponse(MemoryStreamInterface *pStream);

	// ���X�|������M�����B
	void OnRecvRespawn(MemoryStreamInterface *pStream);

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

};

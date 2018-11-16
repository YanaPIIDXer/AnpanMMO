// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include "Character/Player/PlayerManager.h"
#include "Character/Anpan/AnpanManager.h"
#include "WarpPoint/WarpPointManager.h"
#include "ActiveGameMode.generated.h"

class UMainHUD;

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

};

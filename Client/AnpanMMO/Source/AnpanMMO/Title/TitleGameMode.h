// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include <functional>
#include "TitleGameMode.generated.h"

enum PacketID;
class MemoryStreamInterface;
class UTitleScreenWidget;
class UCharacterNameInputWidget;

/**
 * �^�C�g�����GameMode
 */
UCLASS()
class ANPANMMO_API ATitleGameMode : public AMMOGameModeBase
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	ATitleGameMode(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ATitleGameMode() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// ���O�C�����N�G�X�g�𑗐M.
	void SendLogInRequest();

protected:

	// ���O�C������.
	UFUNCTION(BlueprintNativeEvent, Category = "LogIn")
	void OnLogInResult(bool bSuccess);
	void OnLogInResult_Implementation(bool bSuccess) {}

private:
	
	// �^�C�g�����Widget
	UTitleScreenWidget *pScreenWidget;

	// ���O����Widget
	UCharacterNameInputWidget *pNameInputWidget;


	// �ڑ��R�[���o�b�N
	void OnConnectResult(bool bConnected);

	// ���O�C�����ʂ���M�����B
	void OnRecvLogInResult(MemoryStreamInterface *pStream);

	// �L�����N�^�쐬���ʂ���M�����B
	void OnRecvCreateCharacterResult(MemoryStreamInterface *pStream);

	// �L�����N�^�X�e�[�^�X����M�����B
	void OnRecvCharacterStatus(MemoryStreamInterface *pStream);

	// �X�L�����X�g����M�����B
	void OnRecvSkillList(MemoryStreamInterface *pStream);

	// �X�N���v�g�t���O����M�����B
	void OnRecvScriptFlag(MemoryStreamInterface *pStream);

	// �Q�[����ʂɐi�ޏ������o�����B
	void OnReadyToGame();
	
};

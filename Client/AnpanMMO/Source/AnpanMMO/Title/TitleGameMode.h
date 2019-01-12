// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MMOGameModeBase.h"
#include <functional>
#include "TitleGameMode.generated.h"

class PacketID;
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
	bool OnRecvLogInResult(MemoryStreamInterface *pStream);

	// �L�����N�^�쐬���ʂ���M�����B
	bool OnRecvCreateCharacterResult(MemoryStreamInterface *pStream);

	// �L�����N�^�X�e�[�^�X����M�����B
	bool OnRecvCharacterStatus(MemoryStreamInterface *pStream);

	// �X�L�����X�g����M�����B
	bool OnRecvSkillList(MemoryStreamInterface *pStream);

	// �X�L���c���[�f�[�^����M�����B
	bool OnRecvSkillTreeData(MemoryStreamInterface *pStream);

	// �A�C�e�����X�g����M�����B
	bool OnRecvItemList(MemoryStreamInterface *pStream);

	// �A�C�e���V���[�g�J�b�g����M�����B
	bool OnRecvItemShortcut(MemoryStreamInterface *pStream);

	// �X�N���v�g�t���O����M�����B
	bool OnRecvScriptFlag(MemoryStreamInterface *pStream);

	// �N�G�X�g�f�[�^����M�����B
	bool OnRecvQuestData(MemoryStreamInterface *pStream);

	// �Q�[����ʂɐi�ޏ������o�����B
	void OnReadyToGame();
	
};

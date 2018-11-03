// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include <functional>
#include "TitleGameMode.generated.h"

enum PacketID;
class MemoryStreamInterface;
class UTitleScreenWidget;

/**
 * �^�C�g�����GameMode
 */
UCLASS()
class ANPANMMO_API ATitleGameMode : public AGameMode
{

	GENERATED_BODY()

private:		// �ʖ���`.

	typedef TMap<PacketID, std::function<void(MemoryStreamInterface *)>> FunctionMap;
	
public:

	// �R���X�g���N�^
	ATitleGameMode(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ATitleGameMode() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

protected:

	// ���O�C������.
	UFUNCTION(BlueprintNativeEvent, Category = "LogIn")
	void OnLogInResult(bool bSuccess);
	void OnLogInResult_Implementation(bool bSuccess) {}

private:
	
	// �^�C�g�����Widget
	UTitleScreenWidget *pScreenWidget;

	// �p�P�b�g��͊֐��Q.
	FunctionMap PacketFunctions;


	// �ڑ��R�[���o�b�N
	void OnConnectResult(bool bConnected);

	// �p�P�b�g����M�����B
	void OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream);

	// ���O�C�����ʂ���M�����B
	void OnRecvLogInResult(MemoryStreamInterface *pStream);

	// �L�����N�^�X�e�[�^�X����M�����B
	void OnRecvCharacterStatus(MemoryStreamInterface *pStream);

	// �Q�[����ʂɐi�ޏ������o�����B
	void OnReadyToGame();
	
};

// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VersionDownloader.h"
#include "TitleScreenWidget.generated.h"

DECLARE_DELEGATE_OneParam(FOnConnect, bool);
DECLARE_DELEGATE(FOnReadyToGame);

/**
 * �^�C�g�����Widget
 */
UCLASS()
class ANPANMMO_API UTitleScreenWidget : public UUserWidget
{

	GENERATED_BODY()
	
public:

	// ����.
	static UTitleScreenWidget *Show(UObject *pOuter);

	// �R���X�g���N�^
	UTitleScreenWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UTitleScreenWidget() {}

	// �t�F�[�h�J�n.
	UFUNCTION(BlueprintNativeEvent, Category = "Fade")
	void StartFade();
	void StartFade_Implementation() {}

	// ���O�C���Ɏ��s�����B
	UFUNCTION(BlueprintNativeEvent, Category = "Connection")
	void OnFailedLogIn();
	void OnFailedLogIn_Implementation() {}


	// �ڑ��R�[���o�b�N
	FOnConnect OnConnect;

	// �Q�[����ʂɈڍs���鏀���������������̃R�[���o�b�N
	FOnReadyToGame OnReadyToGame;
	
protected:

	// �}�X�^�_�E�����[�h�J�n.
	UFUNCTION(BlueprintCallable, Category = "Master")
	void StartMasterDownload();

	// �}�X�^�_�E�����[�h�����������B
	UFUNCTION(BlueprintNativeEvent, Category = "Master")
	void OnMasterDownloaded(bool bSuccess);
	void OnMasterDownloaded_Implementation(bool bSuccess) {}

	// �X�N���v�g�_�E�����[�h�J�n.
	UFUNCTION(BlueprintCallable,Category = "Script")
	void StartScriptDownload();

	// �X�N���v�g�_�E�����[�h�����������B
	UFUNCTION(BlueprintNativeEvent, Category = "Script")
	void OnScriptDownloaded(bool bSuccess);
	void OnScriptDownloaded_Implementation(bool bSuccess) {}

	// DLC�̃_�E�����[�h�J�n.
	UFUNCTION(BlueprintCallable, Category = "DLC")
	void StartDLCDownload();

	// DLC�_�E�����[�h�����������B
	UFUNCTION(BlueprintNativeEvent, Category = "DLC")
	void OnDLCDownloaded(bool bSuccess);
	void OnDLCDownloaded_Implementation(bool bSuccess) {}

	// �Q�[���T�[�o�ւ̐ڑ�.
	UFUNCTION(BlueprintCallable, Category = "Connection")
	void ConnectToGameServer();

	// �Q�[���T�[�o�ɐڑ������B
	UFUNCTION(BlueprintNativeEvent, Category = "Connection")
	void OnConnectedGameServer(bool bSuccess);
	void OnConnectedGameServer_Implementation(bool bSuccess) {}

	// �t�F�[�h�����������B
	UFUNCTION(BlueprintCallable, Category = "Fade")
	void OnFadeFinish();

private:

	// Widget�̃p�X
	static const TCHAR *WidgetPath;

	// �o�[�W�����_�E�����[�_
	VersionDownloader VersionDownload;

};

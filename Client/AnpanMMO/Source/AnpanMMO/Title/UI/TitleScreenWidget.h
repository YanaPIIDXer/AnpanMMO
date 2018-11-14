// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MasterDownloader.h"
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


	// �ڑ��R�[���o�b�N
	FOnConnect OnConnect;

	// �Q�[����ʂɈڍs���鏀���������������̃R�[���o�b�N
	FOnReadyToGame OnReadyToGame;
	
protected:

	// �}�X�^�_�E�����[�h�J�n.
	UFUNCTION(BlueprintCallable, Category = "Master")
	void StartMasterDownload();

	// �_�E�����[�h�����������B
	UFUNCTION(BlueprintNativeEvent, Category = "Master")
	void OnMasterDownloaded(bool bSuccess);
	void OnMasterDownloaded_Implementation(bool bSuccess) {}

	// �Q�[���T�[�o�ւ̐ڑ�.
	UFUNCTION(BlueprintCallable, Category = "Connection")
	void ConnectToGameServer();

	// �t�F�[�h�����������B
	UFUNCTION(BlueprintCallable, Category = "Fade")
	void OnFadeFinish();

private:

	// Widget�̃p�X
	static const TCHAR *WidgetPath;

	// �}�X�^�_�E�����[�_
	MasterDownloader MasterDownload;

};

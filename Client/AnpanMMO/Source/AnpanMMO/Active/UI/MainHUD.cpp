// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "MainHUD.h"
#include "Util.h"
#include "Character/Player/GameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Active/ActiveGameMode.h"

const TCHAR *UMainHUD::AssetPath = TEXT("/Game/Blueprints/UI/Active/MainHUD.MainHUD");

// �\��.
UMainHUD *UMainHUD::Show(UObject *pOuter)
{
	auto *pWidget = Util::LoadBlueprint<UMainHUD>(pOuter, AssetPath);
	check(pWidget != nullptr);

	pWidget->AddToViewport();
	return pWidget;
}

// �R���X�g���N�^
UMainHUD::UMainHUD(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
	, pCharacter(nullptr)
{
}

// �J�n���̏���.
void UMainHUD::NativeConstruct()
{
	Super::NativeConstruct();

	pCharacter = Cast<AGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}


// �U���{�^���������ꂽ�B
void UMainHUD::OnPressedAttackButton()
{
	pCharacter->Attack();
}

// ���x�����[�h�J�n.
void UMainHUD::StartLevelLoad()
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(this));
	check(pInst != nullptr);

	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	
	uint32 AreaId = pInst->GetAreaIdCache();
	pGameMode->StartLevelLoad(AreaId);
}

// �Q�[�����j���[�\��.
void UMainHUD::ShowGameMenu()
{
	AActiveGameMode *pGameMode = Cast<AActiveGameMode>(UGameplayStatics::GetGameMode(this));
	check(pGameMode != nullptr);
	pGameMode->ShowGameMenu();
}

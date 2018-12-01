// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/DirectionalLight.h"
#include "Classes/Curves/CurveLinearColor.h"
#include "SkyControl.generated.h"

/**
 * �V���̏�ԃR���g���[��Actor
 */
UCLASS()
class ANPANMMO_API ASkyControl : public AActor
{

	GENERATED_BODY()
	
public:	
	
	// �R���X�g���N�^
	ASkyControl(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ASkyControl() {}

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;

	// �}�e���A���̍X�V.
	void RefleshMaterial();

	// ���z�̕������X�V.
	void UpdateSunDirection();

	// �Q�[���O�iEditor�j�ł�Tick�����邩�H
	virtual bool ShouldTickIfViewportsOnly() const override { return true; }

private:

	// �X�J�C�X�t�B�A�̃��b�V��
	UPROPERTY()
	UStaticMeshComponent *pSkySphereMesh;

	// �\�[�X�}�e���A��
	UPROPERTY()
	UMaterial *pSourceMaterial;

	// ��̃}�e���A��
	UPROPERTY()
	UMaterialInstanceDynamic *pSkyMaterial;

	// �}�e���A�����X�V���邩�H
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	bool bRefleshMaterial;

	// �f�B���N�V���i�����C�g
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	ADirectionalLight *pDirectionalLight;

	// ���z�̐F�̉e�����󂯂邩�i�H�j
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	bool bColorsDeterminedBySun;

	// ���z���̋���
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float SunBrightness;

	// �_�̑��x.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float CloudSpeed;

	// �_�̓����x.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float CloudOpacity;

	// ���̌��̋���
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float StarsBrightness;

	// �n�����̃J���[�J�[�u
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	UCurveLinearColor *pHorizonColorCurve;
	
	// �V���̃J���[�J�[�u
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	UCurveLinearColor *pZenithColorCurve;

	// �_�̃J���[�J�[�u
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	UCurveLinearColor *pCloudColorCurve;

	// ���z�̍���
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float SunHeight;

	// �n�����̌���.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	float HorizonFallOff;

	// �V���̐F.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	FLinearColor ZenithColor;

	// �n�����̐F.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	FLinearColor HorizonColor;

	// �_�̐F.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	FLinearColor CloudColor;

	// �S���̐F.
	UPROPERTY(EditAnywhere, Category = "SkyControl")
	FLinearColor OverallColor;

};

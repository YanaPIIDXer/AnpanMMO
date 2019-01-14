// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetCircle.generated.h"

class ACharacterBase;

/**
 * �^�[�Q�b�g�T�[�N��
 */
UCLASS()
class ANPANMMO_API ATargetCircle : public AActor
{

	GENERATED_BODY()
	
public:	

	// �R���X�g���N�^
	ATargetCircle(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~ATargetCircle() {}

	// �L�����N�^���Z�b�g�B
	void SetCharacter(ACharacterBase *pInCharacter);

	// ���t���[���̏���.
	virtual void Tick(float DeltaTime) override;
	
private:

	// �A�Z�b�g�p�X
	static const TCHAR *AssetPath;

	// �����I�t�Z�b�g
	static const float HeightOffset;

	// �P�b�Ԃ̉�]��.
	static const float RotateBySec;

	// StaticMeshComponent
	UPROPERTY()
	UStaticMeshComponent *pMeshCmp;

	// �L�����N�^
	TWeakObjectPtr<ACharacterBase> pCharacter;

};
